/*
** EPITECH PROJECT, 2020
** attack.c
** File description:
** attack
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int check_attack(char *line, int strlen)
{
    int i = 0;
    if (strlen == 0) {
        my_printf("\nwrong position\n");
        return (84);
    }
    if (strlen == 3)
        if (line[i] >= 'A' && line[i] <= 'H'
            && line[i + 1] >= '1' && line[i + 1] <= '8')
            return (0);
        else {
            my_printf("wrong position\n");
            return (84);
        }
    else {
        my_printf("wrong position\n");
        return (84);
    }
}

char *my_attack(void)
{
    char *line = malloc(sizeof(char) * 3);
    int i = 0;
    int j = 0;

    my_printf("\n");
    while (i == 0) {
        my_printf("attack: ");
        j = read(0, line, 4096);
        if (check_attack(line, j) == 0)
            i++;
    }
    my_printf("%c%c: ", line[0], line[1]);
    return (line);
}
