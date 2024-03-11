NAME = push_swap

SRCS = main.c revrotate.c swaps.c perots.c checkers.c sort.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		@make -s -C ft_printf
		@$(CC) $(CFLAGS) -s -o $(NAME) $(OBJ) ft_printf/libftprintf.a
		@echo "makou"
		@echo 888888888888888---88888888888888
		@echo 88888888888888-----8888888888888
		@echo 8888888888888------8888888888888
		@echo 88888888888888-----8888888888888
		@echo 88888888888--------8888888888888
		@echo 88888888888-------88888888888888
		@echo 888888888--------888888888888888
		@echo 8888888----------888888888888888
		@echo 8888-------------------------888
		@echo 888--------888888888888888888888
		@echo 888-------8-------------------88
		@echo -----------8------------------88
		@echo -------------8888888888888888888
		@echo -----------88------------------8
		@echo ----------8--------------------8
		@echo -------------8888888888888888888
		@echo ------------8-----------------88
		@echo -------------8----------------88
		@echo --------------888888888888888888
		@echo -------------8--------------8888
		@echo 888-----------8-------------8888
		@echo 88888888888888888888888888888888


clean:
		@make clean -s -C ft_printf
		@$(RM) $(OBJ)

fclean:	clean
		@make fclean -s -C ft_printf
		@$(RM) $(NAME)
		@echo "apagou"

re:	fclean $(NAME)
	@echo "makou outra vez"