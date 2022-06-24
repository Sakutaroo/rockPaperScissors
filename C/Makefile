SRC	=	src/main.c	\
		src/utility.c

NAME	=	rockPaperScissors

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f src/*~

fclean: clean
	rm -f $(NAME)
	clear

re:	fclean all

debug: fclean
debug:	CFLAGS += -ggdb3
debug: all

.PHONY: all clean fclean re debug
