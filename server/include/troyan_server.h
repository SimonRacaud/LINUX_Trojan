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
#include "app_t.h"
#include "gui.h"

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84

/// Config
#define PORT       12301
#define MAX_CLIENT 1

#define CLIENT_CONNECT "{ CLIENT CONNECTED }"
#define CLIENT_DISCONNECT "{ CLIENT DISCONNECTED }"

#define LOGOUT_CMD "exit"

/// SERVER
int app_start(uint port);
void app_stop(void);
int app_process_fd(app_t *app);

/// CONNECTION
void client_disconnect(server_t *server, window_t *win);
int client_connect(server_t *server, window_t *win);

/// UTILITY
int signal_init(void);


#endif /* !APP_H_ */
