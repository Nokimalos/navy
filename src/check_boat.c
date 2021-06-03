/*
** EPITECH PROJECT, 2020
** check_boat.c
** File description:
** check_boat
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

extern stock_t stock;

int convert_char(char a)
{
    int nb = 0;
    int res = 64;

    while (res < a) {
        res += 1;
        nb += 1;
    }
    return (nb);
}

int convert_int(char b)
{
    int nb = 0;
    int res = 48;

    while (res < b) {
        res += 1;
        nb += 1;
    }
    return (nb);
}

char **our_boat(char **map, int the_char, int the_int, int lose)
{
    int pid = stock.win;

    if (map[the_int - 1][the_char - 1] == '.' ||
        map[the_int - 1][the_char - 1] == 'o' ||
        map[the_int - 1][the_char - 1] == 'x') {
        my_printf("missed\n");
        if (map[the_int - 1][the_char - 1] == '.' ||
        map[the_int - 1][the_char - 1] == 'o')
        map[the_int - 1][the_char - 1] = 'o';
        send_result(2, pid);
        stock.lose = 100;
    } else {
        my_printf("hit\n");
        map[the_int - 1][the_char - 1] = 'x';
        lose += 1;
        send_result(1, pid);
        stock.lose = lose;
    }
    return (map);
}

char **enemy_boat(char **map, int the_char, int the_int, int win)
{
    int receive = receive_result();

    stock.win = win;
    if (receive == 1) {
        my_printf("hit\n");
        map[the_int - 1][the_char - 1] = 'x';
        stock.win += 1;
    }
    else if (receive == 2) {
        my_printf("missed\n");
        map[the_int - 1][the_char - 1] = 'o';
    }
    return (map);
}
