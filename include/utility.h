/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 16/04/2021 utility.h
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void str_to_upper(char *str);
ssize_t find_newline(const char *str);
bool is_empty(const char *str);
char *strconcat(char *a, const char *b);

int write_in_log(size_t size, ...);
bool is_command(const char *command, const char *label);

#endif // UTILITY_H
