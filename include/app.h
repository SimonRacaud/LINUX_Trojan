/*
** EPITECH PROJECT, 2021
** 0_C_BASE_FILES
** File description:
** app
*/

#ifndef APP_H_
#define APP_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#include "socket.h"
#include "daemon.h"
#include "server_t.h"

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

// Config
#define PORT 42
#define MAX_CLIENT 1

// Core
int app_start(void);

int signal_init(void);

int process_command(const char *command, socket_t *client);

int write_in_log(const char *command);

#endif /* !APP_H_ */
