/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 server_t.h
*/

#ifndef SERVER_T_H
#define SERVER_T_H

#include "socket_t.h"
#include <stdbool.h>

typedef struct server {
    socket_t sock;
    bool client_connected;
    socket_t client;
    select_t select;
} server_t;

#endif // SERVER_T_H
