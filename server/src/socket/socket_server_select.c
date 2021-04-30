/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 socket_server_select.c
*/

#include "socket.h"

static void init_fds(
    fd_set *fds, socket_t *client, socket_t *server, int stdin)
{
    FD_ZERO(fds);
    FD_SET(server->fd, fds);
    FD_SET(stdin, fds);
    if (client) {
        FD_SET(client->fd, fds);
    }
}

int socket_server_select(
    select_t *data, socket_t *client, socket_t *server, int stdin)
{
    init_fds(&data->read_fds, client, server, stdin);
    data->status = select(FD_SETSIZE, &data->read_fds, NULL, NULL, NULL);
    if (data->status == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}