NAME = libft.a

SRCS = 	ft_strlen.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_split.c \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c

OBJ = $(SRCS:.c=.o)

B =	ft_lstsize.c \
	ft_lstclear.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstlast.c \

B_OBJ = $(B:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ) $(B_OBJ)

clean:
			$(RM) $(OBJ) $(B_OBJ)

fclean:	clean
			$(RM) $(NAME)

re:	fclean $(NAME)