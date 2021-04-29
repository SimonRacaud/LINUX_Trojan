/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 reader.c
*/

#include "client.h"

static void receive_data(int fd)
{
    char buffer[1024] = {0};
    int n = 0;

    do {
        if ((n = recv(fd, buffer, sizeof(buffer) - 1, MSG_DONTWAIT)) == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
                return;
            perror("recv");
            exit(errno);
        }
        if (n > 0) {
            buffer[n] = '\0';
            printf("%s", buffer);
        }
    } while (n > 0);
}

int reader_start(int fd)
{
    int child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (child_pid == 0) {
        while (true) {
            receive_data(fd);
            usleep(500000);
        }
        exit(EXIT_SUCCESS);
    }
    return EXIT_SUCCESS;
}