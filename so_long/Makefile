NAME = so_long

SRCS = main.c sprites.c colorplayer.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C mlx-linux
		@$(CC) $(CFLAGS) $(OBJ) mlx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -s -C mlx-linux

fclean:	clean
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
	@echo "makou outra vez"