/*
** EPITECH PROJECT, 2020
** my_put_hexa
** File description:
** my_put_hexa
*/

#include <stdio.h>
#include "my.h"

void my_put_hexa(int nb)
{
    int modulo;
    int divide;

    modulo = nb % 16;
    divide = nb / 16;
    if (nb >= 16) {
        my_put_hexa(divide);
    }
    if (modulo <= 9) {
        my_putchar(modulo + 48);
    }
    if (modulo > 9) {
        my_putchar(modulo + 87);
    }
}

void my_puthexa_upper(int nb)
{
    int modulo;
    int divide;

    modulo = nb % 16;
    divide = nb / 16;
    if (nb >= 16) {
        my_puthexa_upper(divide);
    }
    if (modulo <= 9) {
        my_putchar(modulo + 48);
    }
    if (modulo > 9) {
        my_putchar(modulo + 55);
    }
}