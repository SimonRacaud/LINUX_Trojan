/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_create.c
*/

#include "gui.h"

static int window_create(window_t *window, const vector_t size,
    const vector_t position, bool have_box)
{
    window->win = subwin(stdscr, size.y, size.x, position.y, position.x);
    window->show_border = have_box;
    if (window->win == NULL) {
        return EXIT_FAILURE;
    }
    if (have_box)
        box(window->win, ACS_VLINE, ACS_HLINE);
    wrefresh(window->win);
    window->size = size;
    window->position = position;
    return EXIT_SUCCESS;
}

int gui_create(gui_t *gui)
{
    if (initscr() == NULL) {
        perror("initscr");
        return EXIT_FAILURE;
    }
    const size_t PROMPT_HEIGHT = 3;
    const vector_t W_RESULT_SIZE = {COLS, LINES - PROMPT_HEIGHT - 1};
    const vector_t W_RESULT_POS = {0, PROMPT_HEIGHT};
    const vector_t W_PROMPT_POS = {0, 0};
    const vector_t W_PROMPT_SIZE = {COLS, PROMPT_HEIGHT};

    if (window_create(&gui->woutput, W_RESULT_SIZE, W_RESULT_POS, false))
        return EXIT_FAILURE;
    if (window_create(&gui->wprompt, W_PROMPT_SIZE, W_PROMPT_POS, true))
        return EXIT_FAILURE;
    scrollok(gui->woutput.win, TRUE);
    gui_reset_cursor_pos(gui);
    gui_print_footer();
    return EXIT_SUCCESS;
}