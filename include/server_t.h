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

typedef struct select {
    fd_set read_fds;
    int status;
} select_t;

typedef struct shell_s {
    pid_t pid;
    int pipe[2];
} shell_t;

typedef struct server {
    socket_t sock;
    bool client_connected;
    socket_t client;
    shell_t shell;
    select_t select;
} server_t;

#endif // SERVER_T_H
