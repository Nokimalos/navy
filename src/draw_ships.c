/*
** EPITECH PROJECT, 2020
** draw_ships.c
** File description:
** draw_ships
*/

#include "my.h"
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

extern stock_t stock;

int count_cols(char **map, char boat)
{
    int i = 0;

    while (map[0][i] != boat)
        i++;
    return (i);
}

int count_rows(char **map, char boat)
{
    int i = 0;

    while (map[i][0] != boat)
        i++;
    return (i);
}

char **draw_ships(char **map, char *boat)
{
    int i = count_rows(map, boat[3]);
    int j = count_cols(map, boat[2]);
    int k = count_rows(map, boat[6]);
    int l = count_cols(map, boat[5]);

    while (i < k) {
        if (map[i][j] == '.')
            map[i][j] = boat[0];
        i++;
    }
    while (j <= l) {
        if (map[i][j] == '.')
            map[i][j] = boat[0];
        j++;
    }
    return (map);
}

char **write_my_ships(char **map, char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 8);
    int i = 0;

    while (i < 6) {
        read(fd, buffer, 8);
        map = draw_ships(map, buffer);
        i++;
    }
    free(buffer);
    return (map);
}
