/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 29/04/2021 is_command.c
*/

#include "utility.h"

bool is_command(const char *command, const char *label)
{
    for (size_t i = 0; command[i] != '\0'; i++) {
        if (false == isblank(command[i])) {
            if (strncmp(&command[i], label, strlen(label)) == 0) {
                return true;
            }
            return false;
        }
    }
    return false;
}
