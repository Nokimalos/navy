/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game
*/

#include "my.h"
#include <stdlib.h>

extern stock_t stock;

char **play_game_wait(char **map1, int win, int lose, int pid)
{
    int *pos = malloc(sizeof(int) * 2);

    win = stock.win;
    my_printf("\nwaiting for enemy's attack...\n");
    pos[0] = receive_package();
    pos[1] = receive_package();
    my_printf("%c%c: ", (pos[0] + 64), (pos[1] + 48));
    stock.win = pid;
    map1 = our_boat(map1, do_char_map(pos[0]), do_int_map(pos[1]), lose);
    stock.win = win;
    free(pos);
    return (map1);
}

char **play_your_turn(char **map2, int win, int lose, int pid)
{
    char *attack;
    int cols;
    int rows;

    attack = send_package(my_attack(), pid);
    cols = do_char_map(convert_char(attack[0]));
    rows = do_int_map(convert_int(attack[1]));
    stock.win = win;
    stock.lose = lose;
    map2 = enemy_boat(map2, cols, rows, win);
    free(attack);
    return (map2);
}

int play_game_one(int argc, char **argv)
{
    char **map1 = write_my_ships(stock_map(), argv[1]);
    char **map2 = stock_map();
    int win = 0;
    int lose = 0;
    int pid = load_player1();

    while (win < 14) {
        show_menu(map1, map2);
        map2 = play_your_turn(map2, win, lose, pid);
        win = stock.win;
        map1 = play_game_wait(map1, win, lose, pid);
        lose = check_lose(lose);
        if (win == 14 || lose == 14) {
            win = show_result(win, lose, map1, map2);
            break;
        }
    }
    return (win);
}

int play_game_two(int argc, char ** argv)
{
    char **map1 = write_my_ships(stock_map(), argv[2]);
    char **map2 = stock_map();
    int win = 0;
    int lose = 0;
    int pid = load_player2(argv[1]);

    while (win < 14) {
        show_menu(map1, map2);
        map1 = play_game_wait(map1, win, lose, pid);
        lose = check_lose(lose);
        map2 = play_your_turn(map2, win, lose, pid);
        win = stock.win;
        if (win == 14 || lose == 14) {
            win = show_result(win, lose, map1, map2);
            break;
        }
    }
    return (win);
}
