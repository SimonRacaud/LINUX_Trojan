/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 01/05/2021 app_t.h
*/

#ifndef APP_T_H
#define APP_T_H

#include "server_t.h"
#include "gui_t.h"

typedef struct app_s {
    server_t server;
    gui_t gui;
} app_t;

#endif // APP_T_H
