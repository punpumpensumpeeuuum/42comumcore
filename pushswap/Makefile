NAME = push_swap

SRCS = main.c revrotate.c swaps.c checkers.c 

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		make -C ft_printf
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) ft_printf/libftprintf.a

clean:
		make clean -C ft_printf
		$(RM) $(OBJ)

fclean:	clean
		make fclean -C ft_printf
		$(RM) $(NAME)

re:	fclean $(NAME)