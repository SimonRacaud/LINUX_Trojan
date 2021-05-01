/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 main.c
*/

#include "client.h"

int main(void)
{
    if(geteuid() != 0) {
        fprintf(stderr, "Please, run as root\n");
        return EXIT_FAILURE;
    }
    return daemon_start(&client);
}
