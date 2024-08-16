##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

NAME	=	make

LIB	=	-L lib/my/ -lmy

INCLUDE	=	-I ./include/my.h

all: $(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		make -C ./antman
		make -C ./giantman
clean:
	make -C ./lib/my fclean
	make -C ./antman fclean
	make -C ./giantman fclean
	rm -f libmy.a

fclean: clean
	rm -f libmy.a
	rm -f lib/my/libmy.a
	rm -f ./lib/my/*.o

re: fclean all

exec:	re
	./$(NAME)
