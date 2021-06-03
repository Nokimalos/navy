/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my.h"

stock_t stock;

void display_h(void)
{
    my_printf("USAGE\n   ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n   first_player_pid: only for the 2nd player. ");
    my_printf("pid of the first player.\n   navy_positions: ");
    my_printf("file representing the positions of the ships.\n");
}

int main(int argc, char **argv)
{
    int ret;

    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
            display_h();
            return (0);
        } else if (check_all(argv[1]) == 0) {
            stock = initialize(stock);
            ret = play_game_one(argc, argv);
            return (ret);
        }
        else
            return (84);
    }
    else if (argc == 3 && check_all(argv[2]) == 0) {
        stock = initialize(stock);
        ret = play_game_two(argc, argv);
        return (ret);
    } else
        return (84);
}
