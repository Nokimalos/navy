/*
** EPITECH PROJECT, 2020
** my_atoi.c
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int negative = 0;

    while (str[i] != '\0') {
        if (str[i] == '-'){
            negative = 1;
                }
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + str[i] - '0';
        }
        i++;
    }
    if (str[i] == '\0' && negative == 1) {
        return (-nb);
    } else {
        return (nb);
    }
}
