CC=cc
CFLAGS=-Wall -Wextra -Werror -Iheaders -g3 -lm
NAME=fractol

SRCS=
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: all clean fclean re