/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_destroy.c
*/

#include "gui.h"

void gui_destroy(gui_t *gui)
{
    delwin(gui->woutput.win);
    delwin(gui->wprompt.win);
    endwin();
}