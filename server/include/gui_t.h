/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_t.h
*/

#ifndef GUI_T_H
#define GUI_T_H

#include <ncurses.h>
#include "vector_t.h"

typedef struct window_s {
    WINDOW *win;
    vector_t size;
    vector_t position;
    bool show_border;
} window_t;

typedef struct gui_s {
    window_t woutput;
    window_t wprompt;
} gui_t;

#endif // GUI_T_H
