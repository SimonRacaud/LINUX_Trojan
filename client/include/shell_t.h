/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 30/04/2021 shell_t.h
*/

#ifndef SHELL_T_H
#define SHELL_T_H

#include "sys/types.h"

typedef struct shell_s {
    pid_t pid;
    int pipe[2];
} shell_t;

#endif // SHELL_T_H
