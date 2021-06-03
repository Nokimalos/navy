/*
** EPITECH PROJECT, 2020
** check_rectangle.c
** File description:
** check_rectangle
*/

#include "my.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int check_rectangle2(char *buffer, int nb)
{
    if (buffer[2] + nb - 1 == buffer[5] && buffer[3] == buffer[6])
            return (0);
    if (buffer[3] + nb - 1 == buffer[6] && buffer[2] == buffer[5]) {
            return (0);
    } else
        return (84);
}

int check_rectangle(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 8);
    int i = 0;

    while (i < 5) {
        read(fd, buffer, 8);
        if (check_rectangle2(buffer, (buffer[0] - 48)) == 0) {
            i++;
        } else {
            free(buffer);
            close(fd);
            return (84);
        }
    }
    free(buffer);
    close(fd);
    return (0);
}
