##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## antman binary
##

NAME	=	giantman

LIB	=	-L ../lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/read_file.c	\
		src/decompress.c	\
		src/check_insert.c	\
		src/percentage.c	\
		src/words.c	\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
		gcc -g $(OBJ) -o $(NAME) $(LIB) $(INCLUDE)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJ)

re: fclean all

library: fclean

exec:	re
	./$(NAME)
