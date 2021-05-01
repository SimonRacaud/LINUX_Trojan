/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_prompt.c
*/

#include "gui.h"
#include "utility.h"

char *gui_prompt(window_t *win)
{
    char buffer[1024];
    size_t len;

    wclear(win->win);
    if (win->show_border)
        box(win->win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win->win, 1, 2, "$> ");
    if (mvwgetstr(win->win, 1, 5, buffer) == ERR) {
        return NULL;
    }
    if (is_empty(buffer) == false) {
        len = strlen(buffer);
        strcpy(&buffer[len], "\n");
        return strdup(buffer);
    }
    return NULL;
}