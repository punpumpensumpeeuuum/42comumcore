NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_aux.c

LIBSRCS = ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_strdup.c ft_strlen.c ft_strncmp.c \
			ft_split.c ft_substr.c ft_strjoin.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

OBJ = $(SRCS:.c=.o)

LIBOBJ = $(LIBSRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ) $(addprefix libft/,$(LIBOBJ))
		ar rcs $(NAME) $(OBJ) $(addprefix libft/,$(LIBOBJ))

clean:
		$(RM) $(OBJ) $(addprefix libft/,$(LIBOBJ))

fclean:	clean
		$(RM) $(NAME)

re:	fclean $(NAME)