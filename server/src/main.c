/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main function
*/

#include "../include/troyan_server.h"

int main(void)
{
    if(geteuid() != 0) {
        fprintf(stderr, "Please, run as root\n");
        return EXIT_FAILURE;
    }
    return app_start(PORT);
}
