/*
** EPITECH PROJECT, 2020
** my_put_unsigned int
** File description:
** put insigned int
*/

#include "my.h"

int my_unsigned_int(unsigned nb)
{
    int modulo;
    int divide;

    modulo = nb % 10;
    divide = nb / 10;
    if (nb >= 10) {
        my_unsigned_int(divide);
    }
    my_putchar(modulo + 48);
}

void my_insigned_nbr(unsigned nb)
{
    unsigned j = 4294967295;
    if (nb < 0) {
        my_put_nbr(j - nb);
    }
    else {
        my_unsigned_int(nb);
    }
}