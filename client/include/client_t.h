/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 30/04/2021 client_t.h
*/

#ifndef CLIENT_T_H
#define CLIENT_T_H

#include "socket_t.h"
#include "shell_t.h"

typedef struct client_s {
    socket_t socket;
    bool is_connected;
    shell_t shell;
    char *input_buffer;
} client_t;

#endif // CLIENT_T_H
