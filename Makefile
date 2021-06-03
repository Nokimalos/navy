##
## EPITECH PROJECT, 2020
## navy
## File description:
## Makefile
##

SRC		=	src/game_start.c	\
			src/loadmap.c		\
			src/draw_ships.c	\
			src/game.c		\
			src/attack.c		\
			src/check_boat.c	\
			src/package_attack.c	\
			src/package_result.c	\
			src/check_pos.c		\
			src/game_over.c		\
			src/check_rectangle.c	\

OBJ		=	$(SRC:.c=.o)

NAME		=	navy
TEST_NAME	=	unit_tests

LIB 	=	-L lib/my -l my

CFLAGS	=	-I include/

CRITERION =	-lcriterion --coverage

all:	$(NAME)

$(NAME): $(OBJ)
	$(MAKE) re -C lib/my
	gcc -o $(NAME) $(SRC) src/main.c $(LIB) $(CFLAGS)
clean:
	rm -f *.o
	rm -f lib/my/*.o
	rm -f src/*.o
	rm -f *~
	rm -f *.html

tests_run:
	$(MAKE) re -C lib/my
	gcc $(CRITERION) -o $(TEST_NAME) $(SRC) tests/testsmap.c $(LIB) $(CFLAGS)
	-./$(TEST_NAME)

fclean: clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	rm -f lib/my/libmy.a
	rm -f *.gcda
	rm -f *.gcno

re:	fclean all tests_run

.PHONY: all tests_run clean fclean re
