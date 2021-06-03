/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Write a function that put one by one character
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        write(1, &str[i], 1);
        i++;
    }
    return;
}
