## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	my_putstr.c	\
	my_putchar.c	\
	my_put_nbr.c	\
	my_putstr.c	\
	my_put_strocta.c	\
	my_printf.c	\
	put_insigned_nbr.c	\
	my_put_hexa.c	\
	my_put_octa.c	\
	my_put_binary.c	\
	my_put_adress.c	\
	my_atoi.c	\
	my_strlen.c	\
	initialize_global.c

OBJ =	 $(SRC:.c=.o)

W = -W -Wall -Werror

NAME =	libmy.a

CFLAGS = -I ./

all:	libmy.a

libmy.a:	$(OBJ)
	gcc -c $(SRC) $(CFLAGS)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include

clean:
	rm -f *.o
	rm -f *.~
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.a

fclean: clean
	rm -f $(NAME)

re:	fclean all
