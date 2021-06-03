/*
** EPITECH PROJECT, 2020
** check_pos.c
** File description:
** check_pos
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include "my.h"

int check_number_of_pos(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    int res = 2;
    char *buffer = malloc(sizeof(char) * 8);

    if (buffer == NULL || fd == -1)
        return (84);
    while (i < 4) {
        read(fd, buffer, 8);
        if (buffer[0] == '0' + res) {
            res++;
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

int check_pos1(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    char *buffer = malloc(sizeof(char) * 8);

    if (buffer == NULL || fd == -1)
        return (84);
    while (i < 5)
    {
        read(fd, buffer, 8);
        if (buffer[2] >= 'A' && buffer[2] <= 'H'
            && buffer[3] >= '1' && buffer[3] <= '8')
            i++;
        else {
            free(buffer);
            close(fd);
            return (84);
        }
    }
    free(buffer);
    close(fd);
    return (0);
}

int check_pos2(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int i = 0;
    char *buffer = malloc(sizeof(char) * 8);

    if (buffer == NULL || fd == -1)
        return (84);
    while (i < 5)
    {
        read(fd, buffer, 8);
        if (buffer[5] >= 'A' && buffer[5] <= 'H'
            && buffer[6] >= '1' && buffer[6] <= '8')
            i++;
        else {
            free(buffer);
            close(fd);
            return (84);
        }
    }
    free(buffer);
    close(fd);
    return (0);
}

int check_all(char *filepath)
{
    if (check_number_of_pos(filepath) == 84)
        return (84);
    if (check_pos1(filepath) == 84)
        return (84);
    if (check_pos2(filepath) == 84)
        return (84);
    if (check_rectangle(filepath) == 84)
        return (84);
    return (0);
}
