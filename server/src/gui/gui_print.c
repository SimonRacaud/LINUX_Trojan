/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 gui_print.c
*/

#include "gui.h"

static const size_t FOOTER_LEN = 33;

int gui_print(window_t *win, const char *str)
{
    wprintw(win->win, "%s\n", str);
    wrefresh(win->win);
    gui_print_footer();
    return EXIT_SUCCESS;
}

void gui_print_footer(void)
{
    attron(A_BOLD);
    mvprintw(LINES - 1, COLS - FOOTER_LEN, "Epi-Troyan 04/2021 - Simon RACAUD");
    attroff(A_BOLD);
    refresh();
}