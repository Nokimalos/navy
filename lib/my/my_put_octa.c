/*
** EPITECH PROJECT, 2020
** my_put_octa
** File description:
** my_put_octa
*/

#include "my.h"

void my_put_octa(int nb)
{
    int modulo;
    int divide;

    modulo = nb % 8;
    divide = nb / 8;
    if (nb >= 8) {
        my_put_octa(divide);
    }
    my_putchar(modulo + 48);
}
