##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC		=	g++

CFLAGS	=	-Wall -Wextra -g3

SRC		=	main.cpp	\
			Parser.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME	=	groundhog

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all
