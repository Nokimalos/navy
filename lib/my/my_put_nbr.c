/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** put number
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    int modulo;
    int divide;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    modulo = nb % 10;
    divide = nb /10;
    if (nb >= 10) {
        my_put_nbr(divide);
    }
    my_putchar(modulo + 48);
}
