/*
** EPITECH PROJECT, 2020
** printf
** File description:
** printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"

void my_check_flags(char *str, va_list list, int i)
{
    i++;
    if (str[i] == 's')
        my_putstr(va_arg(list, char *));
    if (str[i] == 'c')
        my_putchar(va_arg(list, int));
    if (str[i] == 'd' || str[i] == 'i')
        my_put_nbr(va_arg(list, int));
    if (str[i] == 'S')
        my_put_strocta(va_arg(list, char *));
    if (str[i] == 'u')
        my_insigned_nbr(va_arg(list, int));
    if (str[i] == 'x')
        my_put_hexa(va_arg(list, int));
    if (str[i] == 'X')
        my_puthexa_upper(va_arg(list, int));
    if (str[i] == 'o')
        my_put_octa(va_arg(list, int));
    if (str[i] == 'b')
        my_put_binary(va_arg(list, int));
    if (str[i] == 'p')
        my_put_address(va_arg(list, long int));
}

void my_check_flags2(char *str, va_list list, int i)
{
    i++;
    if (str[i] == '%')
        my_putchar('%');
}

void my_printf(char *str, ...)
{
    va_list list;
    int i = 0;

    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            my_check_flags(str, list, i);
            my_check_flags2(str, list, i);
            i += 2;
        } else {
        my_putchar(str[i]);
        i++;
        }
        }
    va_end(list);
}