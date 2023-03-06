##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-philemon.linossier
## File description:
## makefile
##

SRC =      	src/main.c \
			src/utils.c \
			src/open_file.c \
			src/alloc_2d.c \
			src/change_values.c \
			src/solve_map.c \
			src/bigest_square.c \
			src/generator.c

CFLAGS =    -Wall -Wextra -g3

CC =		gcc -o bsq

OBJ =      	$(SRC:.c=.o)

NAME =  	bsq

$(NAME):    $(OBJ)
	$(CC) $(OBJ) $(CFLAGS)

all:    $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm bsq

re: fclean all
