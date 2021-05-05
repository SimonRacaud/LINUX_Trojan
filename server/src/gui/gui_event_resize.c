/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 05/05/2021 gui_event_resize.c
*/

#include <signal.h>
#include "gui.h"

gui_t *signal_gui_ptr = NULL;

static void sigwinch_handler(__attribute__((unused)) int signum)
{
    if (signal_gui_ptr != NULL) {
        gui_destroy(signal_gui_ptr);
        clear();
        gui_create(signal_gui_ptr);
    }
}

void gui_event_resize_init(gui_t *gui)
{
    signal_gui_ptr = gui;
    signal(SIGWINCH, &sigwinch_handler);
}