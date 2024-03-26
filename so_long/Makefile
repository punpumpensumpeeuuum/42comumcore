NAME = so_long

SRCS = main.c

MLX = minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -lXext -lX11 -L/usr/local/lib

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
	@echo "makou outra vez"