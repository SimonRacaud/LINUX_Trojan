/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 15/04/2021 socket_receive.c
*/

#include "socket.h"

static const size_t BUFF_SIZE = 42;

static bool have_newline(const char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            return true;
        }
    }
    return false;
}

static char *realloc_line(char *line, size_t *len, size_t line_len)
{
    char *new;

    if (line_len + BUFF_SIZE <= *len) {
        return line;
    }
    new = realloc(line, (*len) + BUFF_SIZE);
    *len += BUFF_SIZE;
    return new;
}

char *get_line(int fd, size_t *line_len, char *line)
{
    size_t len = BUFF_SIZE;
    ssize_t current;

    while (line && have_newline(line) == false) {
        current = read(fd, &line[*line_len], BUFF_SIZE);
        if (current == -1) {
            perror("read");
            return NULL;
        }
        (*line_len) += current;
        line[*line_len] = '\0';
        line = realloc_line(line, &len, *line_len);
    }
    return line;
}

char *socket_receive(socket_t *sock)
{
    size_t line_len = 0;
    char *line = calloc(1, sizeof(char) * (BUFF_SIZE + 1));

    if (!line)
        return NULL;
    line = get_line(sock->fd, &line_len, line);
    if (!line)
        return NULL;
    return line;
}