/*
** EPITECH PROJECT, 2020
** package.c
** File description:
** package
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <signal.h>

extern stock_t stock;

int do_char_map(int nb)
{
    int i = 0;
    int res = 1;

    if (nb > 8 || nb <= 0) {
        return (84);
    } else {
        while (i < nb) {
            res += 2;
            i++;
        }
        return (res);
    }
}

int do_int_map(int nb)
{
    int res = 1;

    if (nb > 8 || nb <= 0)
        return (84);
    else {
        res = nb + 2;
        return (res);
    }
}

char *send_package(char *line, int pid)
{
    int i = 64;

    while (i < line[0]) {
        kill(pid, SIGUSR1);
        usleep(10000);
        i++;
    }
    kill(pid, SIGUSR2);
    i = 0;
    usleep(10000);
    while (i < (line[1] - '0')) {
        kill(pid, SIGUSR1);
        usleep(10000);
        i++;
    }
    kill(pid, SIGUSR2);
    return (line);
}

void sig_package(int signal, siginfo_t *info, void *context)
{
    if (signal == SIGUSR1)
        stock.win++;
    else if (signal == SIGUSR2)
        stock.lose = 100;
}

int receive_package(void)
{
    struct sigaction sa;
    int i = 0;

    stock.win = 0;
    stock.lose = 0;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_package;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        if (stock.lose == 100)
            break;
    }
    i = stock.win;
    return (i);
}
