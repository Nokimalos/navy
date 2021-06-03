/*
** EPITECH PROJECT, 2020
** game_over.c
** File description:
** game_over
*/

#include "my.h"
#include <stdlib.h>

extern stock_t stock;

void clean_my_map(char **map1, char **map2)
{
    int i = 0;

    while (i < 11) {
        free(map1[i]);
        free(map2[i]);
        i++;
    }
    free(map1);
    free(map2);
}

int check_lose(int nb)
{
    if (stock.lose == 100)
        return (nb);
    else {
        nb = stock.lose;
        return (nb);
    }
}

int show_result(int win, int lose, char **map1, char **map2)
{
    show_menu(map1, map2);
    clean_my_map(map1, map2);
    if (win == 14) {
        my_printf("\nI won\n");
        return (0);
     } else if (lose == 14) {
        my_printf("\nEnemy won\n");
        return (1);
     }
}
