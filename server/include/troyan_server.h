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

#define CLIENT_CONNECT "{ CLIENT CONNECTED }"
#define CLIENT_DISCONNECT "{ CLIENT DISCONNECTED }"

#define LOGOUT_CMD "exit"

/// SERVER
int troyan_server_start(uint port);
void app_stop(void);
int app_process_request(server_t *server);

/// CONNECTION
void client_disconnect(server_t *server);
int client_connect(server_t *server);

/// UTILITY
int signal_init(void);


#endif /* !APP_H_ */
