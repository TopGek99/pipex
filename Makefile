NAME=pipex
CC=gcc
CFLAGS=-Wall -Wextra -Werror -I$(INC_DIR) -Ilibft/includes
LDFLAGS=-Llibft -lft

OBJ_DIR=obj
SRC_DIR=src
INC_DIR=includes

_INC = pipex.h
INC = $(patsubst %, $(INC_DIR)/%, $(_INC))

_OBJ = pipex.o
OBJ = $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


.PHONY: clean

clean:
	rm -f $(OBJ_DIR)/*.o

fclean:
	rm -f $(OBJ_DIR)/*.o $(NAME)

re: fclean all