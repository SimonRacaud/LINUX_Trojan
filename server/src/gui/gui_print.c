/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_print.c
*/

#include "gui.h"

int gui_print(window_t *win, const char *str)
{
    wprintw(win->win, "%s\n", str);
    wrefresh(win->win);
    return EXIT_SUCCESS;
}