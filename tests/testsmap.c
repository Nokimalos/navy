/*
** EPITECH PROJECT, 2020
** myprintf
** File description:
** myprintf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include <stddef.h>
#include <signal.h>

stock_t stock;

void  redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(convert_int , convert_number)
{
    initialize(stock);

    cr_assert_eq(convert_int('1'), 1);
    cr_assert_eq(convert_int('2'), 2);
    cr_assert_eq(convert_int('3'), 3);
    cr_assert_eq(convert_int('4'), 4);
    cr_assert_eq(convert_int('5'), 5);
    cr_assert_eq(convert_int('6'), 6);
    cr_assert_eq(convert_int('7'), 7);
    cr_assert_eq(convert_int('8'), 8);
}

Test(convert_char , convert_letters)
{
    initialize(stock);

    cr_assert_eq(convert_char('A'), 1);
    cr_assert_eq(convert_char('B'), 2);
    cr_assert_eq(convert_char('C'), 3);
    cr_assert_eq(convert_char('D'), 4);
    cr_assert_eq(convert_char('E'), 5);
    cr_assert_eq(convert_char('F'), 6);
    cr_assert_eq(convert_char('G'), 7);
    cr_assert_eq(convert_char('H'), 8);
}

Test(check_number_of_pos, test_true)
{
    int i = check_number_of_pos("maps/my_navy.txt");
    int j = check_number_of_pos("maps/my_navy2.txt");

    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
}

Test(check_number_of_pos, test_false)
{
    int i = check_number_of_pos("maps/map");
    int j = check_number_of_pos("tests/file_test1.txt");

    cr_assert_eq(i, 84);
    cr_assert_eq(j, 84);
}

Test(check_pos1, test_true)
{
    int i = check_pos1("maps/my_navy.txt");
    int j = check_pos1("maps/my_navy2.txt");

    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
}

Test(check_pos1, test_false)
{
    int i = check_pos1("maps/maps");
    int j = check_pos1("maps/qsdqsd.txt");
    int k = check_pos1("tests/file_test2.txt");

    cr_assert_eq(i, 84);
    cr_assert_eq(j, 84);
    cr_assert_eq(k, 84);
}

Test(check_pos2, test_true)
{
    int i = check_pos2("maps/my_navy.txt");
    int j = check_pos2("maps/my_navy2.txt");

    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
}


Test(check_pos2, test_false)
{
    int i = check_pos2("maps/maps");
    int j = check_pos2("mapqsdst3.txt");
    int k = check_pos2("tests/file_test3.txt");

    cr_assert_eq(i, 84);
    cr_assert_eq(j, 84);
    cr_assert_eq(k, 84);
}

Test(check_all, test_true)
{
    int i = check_all("maps/my_navy.txt");
    int j = check_all("maps/my_navy2.txt");

    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
}

Test(check_rectangle, test_true)
{
    cr_assert_eq(check_rectangle("maps/my_navy.txt"), 0);
    cr_assert_eq(check_rectangle("maps/my_navy2.txt"), 0);
}

Test(check_rectangle, test_false)
{
    cr_assert_eq(check_rectangle("tests/file_test1.txt"), 84);
    cr_assert_eq(check_rectangle("tests/file_test3.txt"), 84);
}

Test(check_all, test_false)
{
    int i = check_all("maps/maps");
    int j = check_all("tests/file_test3.txt");
    int k = check_all("tests/file_test2.txt");
    int l = check_all("tests/file_test1.txt");
    int m = check_all("tests/abc.txt");

    cr_assert_eq(i, 84);
    cr_assert_eq(j, 84);
    cr_assert_eq(k, 84);
    cr_assert_eq(l, 84);
    cr_assert_eq(m, 84);
}

Test(count_cols, map_cols)
{
    char **map = stock_map();

    cr_assert_eq(count_cols(map, 'A'), 2);
    cr_assert_eq(count_cols(map, 'B'), 4);
    cr_assert_eq(count_cols(map, 'C'), 6);
    cr_assert_eq(count_cols(map, 'D'), 8);
    cr_assert_eq(count_cols(map, 'E'), 10);
    cr_assert_eq(count_cols(map, 'F'), 12);
    cr_assert_eq(count_cols(map, 'G'), 14);
    cr_assert_eq(count_cols(map, 'H'), 16);
}

Test(count_rows, map_rows)
{
    char **map = stock_map();

    cr_assert_eq(count_rows(map, '1'), 2);
    cr_assert_eq(count_rows(map, '2'), 3);
    cr_assert_eq(count_rows(map, '3'), 4);
    cr_assert_eq(count_rows(map, '4'), 5);
    cr_assert_eq(count_rows(map, '5'), 6);
    cr_assert_eq(count_rows(map, '6'), 7);
    cr_assert_eq(count_rows(map, '7'), 8);
    cr_assert_eq(count_rows(map, '8'), 9);
}

Test(check_lose, test_true)
{
    stock.lose = 100;
    cr_assert_eq(check_lose(1), 1);
    stock.lose = 0;
}

Test(check_lose, test_false)
{
    stock.lose = 0;
    cr_assert_eq(check_lose(1), 0);
}

Test(do_char_map, map_cols)
{
    cr_assert_eq(do_char_map(1), 3);
    cr_assert_eq(do_char_map(2), 5);
    cr_assert_eq(do_char_map(3), 7);
    cr_assert_eq(do_char_map(4), 9);
    cr_assert_eq(do_char_map(5), 11);
    cr_assert_eq(do_char_map(6), 13);
    cr_assert_eq(do_char_map(7), 15);
    cr_assert_eq(do_char_map(8), 17);
    cr_assert_eq(do_char_map(64), 84);
}

Test(do_int_map, map_rows)
{
    cr_assert_eq(do_int_map(1), 3);
    cr_assert_eq(do_int_map(2), 4);
    cr_assert_eq(do_int_map(3), 5);
    cr_assert_eq(do_int_map(4), 6);
    cr_assert_eq(do_int_map(5), 7);
    cr_assert_eq(do_int_map(6), 8);
    cr_assert_eq(do_int_map(7), 9);
    cr_assert_eq(do_int_map(8), 10);
    cr_assert_eq(do_int_map(64), 84);
}

Test(clean_my_void, clean)
{
    char **map = stock_map();
    char **map2 = stock_map();

    clean_my_map(map, map2);
}


Test(our_boat, verify_attack, .init = redirect_all_std)
{
    char *map_test[] = {" |A B C D E F G H\n", "-+---------------\n", "1|o . . . . . . .\n",
    "2|. . . . . . . .\n", "3|. . . . . . . .\n", "4|. . . . . . . .\n", "5|. . . . . . . .\n",
    "6|. . . . . . . .\n", "7|. . . . . . . .\n", "8|. . . . . . . ."};

    char **map_res = stock_map();
    int i = 0;

    stock.win = 12345;
    map_res = our_boat(map_res, 3, 3, 3);
    while  (i < 10) {
        cr_assert_str_eq(map_test[i], map_res[i]);
        i++;
    }
    map_res = our_boat(map_res, 3, 3, 3);
    i = 0;
    while  (i < 10) {
        cr_assert_str_eq(map_test[i], map_res[i]);
        i++;
    }
    cr_assert_stdout_eq_str("missed\nmissed\n");
}

Test(our_boat, verify_attack2, .init = redirect_all_std)
{
    char *map_test[] = {" |A B C D E F G H\n", "-+---------------\n", "1|. . x . . . . .\n",
    "2|. . 2 . . . . .\n", "3|. . . . . . . .\n", "4|. . . 3 3 3 . .\n", "5|. 4 . . . . . .\n",
    "6|. 4 . . . . . .\n", "7|. 4 . 5 5 5 5 5\n", "8|. 4 . . . . . ." };

    char **map_res = write_my_ships(stock_map(), "maps/my_navy.txt");
    int i = 0;

    stock.win = 12345;
    map_res = our_boat(map_res, 7, 3, 3);
    stock.win = 0;
    while  (i < 10) {
        cr_assert_str_eq(map_test[i], map_res[i]);
        i++;
    }
    cr_assert_stdout_eq_str("hit\n");
}

Test(check_attack, test_true)
{
    int i = check_attack("C1\n", 3);
    int j = check_attack("H8\n", 3);
    int k = check_attack("D4\n", 3);

    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
    cr_assert_eq(k, 0);
}

Test(check_attack, test_false, .init = redirect_all_std)
{
    int i = check_attack("Z1\n", 3);
    int j = check_attack("E9\n", 3);
    int k = check_attack("DD\n", 3);
    int l = check_attack("11\n", 3);
    int m = check_attack("A31\n", 4);

    cr_assert_eq(i, 84);
    cr_assert_eq(j, 84);
    cr_assert_eq(k, 84);
    cr_assert_eq(l, 84);
    cr_assert_eq(m, 84);
    cr_assert_stdout_eq_str("wrong position\nwrong position\nwrong position\nwrong position\nwrong position\n");
}
