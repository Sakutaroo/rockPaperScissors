SRC	=	src/main.cpp

NAME	=	rockPaperScissors

OBJ	=	$(SRC:.cpp=.o)

CC	=	g++

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
