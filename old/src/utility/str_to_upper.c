/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myftp-simon.racaud
** File description:
** 19/04/2021 str_to_upper.c
*/

#include <stddef.h>
#include <ctype.h>

void str_to_upper(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
