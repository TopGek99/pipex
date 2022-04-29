NAME = libft.a
INC = -Iincludes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC_DIR = srcs/
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strjoin.c ft_strlen.c ft_striteri.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printcsdi.c ft_printu.c ft_printxp.c ft_printf.c
LIB_SRCS = $(addprefix $(SRC_DIR),$(SRCS))

OBJ_DIR = objs/
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(addprefix $(OBJ_DIR),$(OBJS))

all: $(NAME)

$(NAME): $(LIB_OBJS)
	$(AR) $(NAME) $(LIB_OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -o $@ -c $< $(INC)

clean:
	$(RM) $(LIB_OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
