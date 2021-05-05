/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui.h
*/

#ifndef GUI_H
#define GUI_H

#include <stdlib.h>

#include "gui_t.h"

int gui_create(gui_t *gui);
void gui_destroy(gui_t *gui);

int gui_print(window_t *win, const char *str);
char *gui_prompt(window_t *win);
void gui_print_footer(void);

void gui_reset_cursor_pos(gui_t *gui);

// Handle window resize
void gui_event_resize_init(gui_t *gui);

#endif // GUI_H
