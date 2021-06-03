/*
** EPITECH PROJECT, 2020
** my_put_octa
** File description:
** my_put_octa
*/

#include "my.h"
#include <string.h>

void my_put_octa1(int nb)
{
    int modulo;
    int divide;

    my_putchar('0');
    my_putchar('0');
    modulo = nb % 8;
    my_putchar(modulo + 48);

}

void my_put_octa2(int nb)
{
    int modulo;
    int divide;

    my_putchar('0');
    divide = nb / 8;
    my_putchar(divide + 48);
    modulo = nb % 8;
    my_putchar(modulo + 48);
}

void my_check_octa(int nb)
{
    if (nb > 7) {
        my_put_octa2(nb);
    } else {
        my_put_octa1(nb);
    }
}

void my_put_strocta(char *str)
{
    int i = 0;

    while (str[i] != ('\0')) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            my_check_octa(str[i]);
            i++;
            }
        my_putchar(str[i]);
        i++;
    }
}