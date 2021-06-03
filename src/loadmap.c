/*
** EPITECH PROJECT, 2020
** loadmap.c
** File description:
** loadmap
*/

#include "my.h"
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

extern stock_t stock;

char **stock_map(void)
{
    int i = 0;
    int fd = open("./maps/map", O_RDONLY);
    int length;
    char **array = malloc(sizeof(char *) * 10);

    if (array == NULL)
        return (NULL);
    while (i <= 10) {
        array[i] = malloc(sizeof(char) * 18);
        if (array[i] == NULL)
            return (NULL);
        i++;
    }
    i = 0;
    while (i != 10) {
        read(fd, array[i], 17 + 1 );
        i++;
    }
    close(fd);
    return (array);
}

void show_menu(char **map1, char **map2)
{
    int nb_rows = 10;

    my_printf("\nmy positions:\n");
    for (int i = 0; i < nb_rows; i++)
        my_printf("%s", map1[i]);
    my_putchar('\n');
    my_printf("\nenemy's positions:\n");
    for (int i = 0; i < nb_rows; i++)
        my_printf("%s", map2[i]);
    my_putchar('\n');
}
