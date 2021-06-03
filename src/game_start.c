/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "my.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>


extern stock_t stock;

void sig_handler(int signal, siginfo_t *info, void *context)
{
    if (signal == SIGUSR1) {
        my_printf("enemy connected\n");
        stock.win = info->si_pid;
        kill(stock.win, SIGUSR2);
    } else if (signal == SIGUSR2) {
    }
}

int load_player1(void)
{
    struct sigaction sa;
    int pid;

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    pid = stock.win;
    stock.win = 0;
    return (pid);
}

int load_player2(char *pid)
{
    struct sigaction sa;
    int his_pid = my_atoi(pid);

    my_printf("my_pid: %d\n", getpid());
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    sigaction(SIGUSR2, &sa, NULL);
    kill(his_pid, SIGUSR1);
    pause();
    my_printf("successfully connected\n");
    return (his_pid);
}
