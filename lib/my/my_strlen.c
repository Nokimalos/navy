/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** count characters
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
