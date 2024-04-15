NAME = so_long

SRCS = main.c sprites.c colorplayer.c toggles.c maps.c mapverify.c placeimage.c closegame.c argmap.c interactions.c path.c

GNL = get_next_line_utils.c get_next_line.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C ft_printf
		@make -s -C mlx-linux
		@$(CC) -g $(CFLAGS) $(OBJ) $(addprefix get_next_line/,$(GNL)) ft_printf/libftprintf.a mlx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -s -C mlx-linux
		@make clean -s -C ft_printf

fclean:	clean
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
		@echo "makou outra vez"