##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project
##

NAME	=	109titration

SRC	=	src/main.c 		\
		src/start.c		\
		src/error_handling.c	\
		src/write_error.c	\
		src/my_strlen.c

CC	=	gcc

DEFLAGS	=	-W -Wextra -Wall -lm

CPPFLAGS	=	-I./include/

CFFLAGS	=	tests/unit_tests.c -I./include --coverage -lcriterion

LDFLAGS	=	-lm

OBJ	=	$(SRC:.c=.o)

all	:	$(OBJ)
		$(CC) $(DEFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS)

debug	:	DEFLAGS += -g3
debug	:	$(all)

tests_run	:
		$(CC) -o unit_tests src/*.c $(CFFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)		\
		rm -f *# 		\
		rm -f src/*# 		\
		rm -f include/*# 	\
		rm -f *~ 		\
		rm -f src/*~ 		\
		rm -f include/*~ 	\
		rm -f *.gcda 		\
		rm -f *.gcno		\
		tree

re	:	fclean all

.PHONY	:	all tests_run clean fclean re
