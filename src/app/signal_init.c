/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 signal_init.c
*/

#include "app.h"
#include <signal.h>
#include "socket.h"

extern bool loop;

static void signal_handler(__attribute__((unused))int code)
{
    fprintf(stderr, "SIGNAL RECEIVED\n");
    loop = false;
}

int signal_init(void)
{
    if (signal(SIGINT, &signal_handler) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }
    if (signal(SIGTERM, signal_handler) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}