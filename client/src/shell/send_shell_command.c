/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 28/04/2021 shell_client.c
*/

#include "client.h"

int send_shell_command(shell_t *shell, const char *command)
{
    if (dprintf(shell->pipe[1], "%s\n", command) == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

