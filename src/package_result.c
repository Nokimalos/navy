/*
** EPITECH PROJECT, 2020
** draw_ships.c
** File description:
** draw_ships
*/

#include "my.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

extern stock_t stock;

void sig_result(int signal, siginfo_t *info, void *context)
{
    if (signal == SIGUSR1)
        stock.win++;
    else if (signal == SIGUSR2)
        stock.lose = 100;
}

int send_result(int nb, int pid)
{
    int i = 0;

    if (nb == 2) {
        while (i < 2) {
            kill(pid, SIGUSR1);
            usleep(10000);
            i++;
        }
        kill(pid, SIGUSR2);
    } else if (nb == 1) {
        while (i < 1) {
            kill(pid, SIGUSR1);
            usleep(10000);
            i++;
        }
        kill(pid, SIGUSR2);
    }
    return (0);
}

int receive_result(void)
{
    struct sigaction sa;
    int i = 0;

    stock.win = 0;
    stock.lose = 0;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_result;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        if (stock.lose == 100)
            break;
    }
    i = stock.win;
    return (i);
}
