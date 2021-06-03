/*
** EPITECH PROJECT, 2020
** %p
** File description:
** function for %p
*/

#include "my.h"

void my_base_adress(long int nb)
{
    long int modulo;
    long int divide;

    modulo = nb % 16;
    divide = nb / 16;
    if (nb >= 16) {
        my_base_adress(divide);
    }
    if (modulo <= 9) {
        my_putchar(modulo + 48);
    }
    if (modulo > 9) {
        my_putchar(modulo + 87);
    }
}

void my_put_address(long int nb)
{
    my_putstr("0x");
    my_base_adress(nb);
}