##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## antman binary
##

NAME	=	antman

LIB	=	-L ../lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	=	src/main.c	\
		src/compress_txt.c	\
		src/print.c	\
		src/check.c	\

OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME): 	$(OBJ)
		gcc -g $(OBJ) -o $(NAME) $(LIB) $(INCLUDE)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
