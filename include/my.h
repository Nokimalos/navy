/*
** EPITECH PROJECT, 2020
** bistromatic.h
** File description:
** macro for bistro
*/

#ifndef my_h
#define my_h

typedef struct stock_s {
    int win;
    int lose;
}stock_t;

char **my_alloc_tab(char **argv);

void my_putchar(char c);

void my_putstr(char const *str);

void my_put_nbr(int nb);

void my_printf(char *str, ...);

void my_put_strocta(char *str);

void my_put_hexa(int nb);

void my_puthexa_upper(int nb);

void my_put_address(long int nb);

void my_insigned_nbr(unsigned nb);

void my_put_octa(int nb);

void my_put_binary(int nb);

int my_compute_power_it(int nb, int p);

char *my_revstr(char *str);

int my_strlen(char const *str);

int my_atoi(char *str);

int load_player1(void);

int load_player2(char *pid);

char **stock_map(void);

void show_menu(char **map1, char **map2);

int count_cols(char **map, char boat);

int count_rows(char **map, char boat);

char **draw_ships(char **map, char *boat);

char **write_my_ships(char **map, char const *filepath);

int play_game_one(int argc, char **argv);

int play_game_two(int argc, char **argv);

char *send_package(char *line, int pid);

int check_attack(char *line, int strlen);

char *my_attack(void);

int receive_package(void);

int do_char_map(int nb);

int do_int_map(int nb);

int convert_char(char a);

int convert_int(char b);

char **our_boat(char **map, int the_char, int the_int, int lose);

char **enemy_boat(char **map, int the_char, int the_int, int win);

int send_result(int nb, int pid);

int receive_result(void);

int check_lose(int nb);

int show_result(int win, int lose, char **map1, char **map2);

int check_number_of_pos(char *filepath);

int check_pos1(char *filepath);

int check_pos2(char *filepath);

int check_all(char *filepath);

stock_t initialize(stock_t stock);

void clean_my_map(char **map1, char **map2);

int check_rectangle(char *filepath);

#endif
