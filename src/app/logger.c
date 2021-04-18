/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 logger.c
*/

#include "app.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static const char *FILENAME = "log.txt";

int write_in_log(const char *command)
{
    static int fd = -1;

    if (fd == -1) {
        fd = open(FILENAME, O_CREAT | O_APPEND | O_WRONLY,
            S_IRWXU | S_IRGRP | S_IROTH);
    } else if (!command) {
        return close(fd);
    }
    if (write(fd, command, strlen(command)) == -1) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}