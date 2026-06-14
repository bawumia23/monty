CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SRC = main.c opcode_funcs.c opcode_funcs2.c opcode_funcs3.c
OBJ = $(SRC:.c=.o)
NAME = monty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
