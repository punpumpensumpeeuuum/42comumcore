NAME = pipex

SRCS = main.c execmds.c

GNL = get_next_line_utils.c get_next_line.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -s -C ft_printf
		@$(CC) -g $(CFLAGS) $(OBJ) $(addprefix get_next_line/,$(GNL)) ft_printf/libftprintf.a -o $(NAME)

clean:
		@$(RM) $(OBJ)
		@make clean -s -C ft_printf

fclean:	clean
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
		@echo "makou outra vez"