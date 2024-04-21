NAME = so_long

SRCS = main.c move.c toggles.c steps.c closegame.c argmap.c

COL = interactions.c colisions.c redcolision.c bluecolision.c greencolision.c

GNL = get_next_line_utils.c get_next_line.c

SPR = animationsprite.c atribuitionsprite.c placeimage.c colorplayer.c

MAP = maps.c mapverify.c path.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C ft_printf
		@make -s -C mlx-linux
		@$(CC) -g $(CFLAGS) $(OBJ) $(addprefix colisions/,$(COL)) $(addprefix map/,$(MAP)) $(addprefix sprites/,$(SPR)) $(addprefix get_next_line/,$(GNL)) ft_printf/libftprintf.a mlx-linux/libmlx_Linux.a -lXext -lX11 -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -s -C mlx-linux
		@make clean -s -C ft_printf

fclean:	clean
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
		@echo "makou outra vez"