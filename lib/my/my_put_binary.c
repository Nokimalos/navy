/*
** EPITECH PROJECT, 2020
** my_put_binaire.c
** File description:
** my_put_binaire.c
*/

#include <stdio.h>
#include "my.h"
#include <stdlib.h>

void my_put_binary(int nb)
{
    int modulo;
    int divide;

    modulo = nb % 2;
    divide = nb / 2;
    if (nb >= 2) {
        my_put_binary(divide);
    }
    my_putchar(modulo + 48);
}