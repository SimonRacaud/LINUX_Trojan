/*
** EPITECH PROJECT, 2021
** HUB_my_troyan
** File description:
** 18/04/2021 daemon.h
*/

#ifndef DAEMON_H
#define DAEMON_H

typedef int (* core_func)(void);

int daemon_start(core_func function);

int daemon_init(void);

#endif // DAEMON_H
