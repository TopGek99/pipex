NAME=pipex
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR) -Ilibft/includes
LDFLAGS=-Llibft -lft

SRC_DIR=src
INC_DIR=includes

_INC = pipex.h
INC = $(patsubst %, $(INC_DIR)/%, $(_INC))

OBJ = 	pipex.o main.o

all: $(NAME)

%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


.PHONY: clean

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)

re: fclean all