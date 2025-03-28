CC=cc
CFLAGS=-Wall -Wextra -Werror -Iheaders -g3 -lm
NAME=fractol
ARCHIVES=minilibx-linux/libmlx_Linux.a

SRCS=main.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf *.o

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: all clean fclean re