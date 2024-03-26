NAME = push_swap

SRCS = main.c revrotate.c swaps.c perots.c checkers.c sort.c freetudo.c stack_a.c stack_b.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		@make -s -C ft_printf
		@$(CC) $(CFLAGS) -s -o $(NAME) $(OBJ) ft_printf/libftprintf.a
		@echo "makou"

clean:
		@make clean -s -C ft_printf
		@$(RM) $(OBJ)

fclean:	clean
		@make fclean -s -C ft_printf
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
		@echo "makou outra vez"