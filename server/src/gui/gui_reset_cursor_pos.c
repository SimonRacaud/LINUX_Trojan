/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_reset_cursor_pos.c
*/

#include "gui.h"

void gui_reset_cursor_pos(gui_t *gui)
{
    mvwprintw(gui->wprompt.win, 1, 2, "");
    wrefresh(gui->wprompt.win);
}