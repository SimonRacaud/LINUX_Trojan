/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 socket_server_connect.c
*/

#include "socket.h"

void debug_socket(socket_t *sock, const char *msg)
{
    char ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(sock->conf.sin_addr), ip, INET_ADDRSTRLEN);
    fprintf(stderr, "%s: ip(%s), port(%u)\n", msg, ip,
            sock->conf.sin_port);
}

int socket_server_connect(socket_t *client, int server_fd)
{
    socklen_t addr_size = sizeof(struct sockaddr);

    client->fd =
        accept(server_fd, (struct sockaddr *) &client->conf, &addr_size);
    if (client->fd == -1) {
        return EXIT_FAILURE;
    }
    #ifdef DEBUG
    debug_socket(client, "Client connected");
    #endif
    return EXIT_SUCCESS;
}