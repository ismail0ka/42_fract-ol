CC=cc
CFLAGS=-Wall -Wextra -Werror -Iheaders -g3
LDFLAGS=-lm -lX11 -lXext
NAME=fractol
ARCHIVES=.minilibx-linux/libmlx_Linux.a

SRCS=main.c \
	fractals/mandelbrot.c \
	fractals/julia.c \
	utils/initialization.c \
	utils/render_fractal.c \
	utils/ft_atof.c \
	utils/ft_strncmp.c \
	utils/events.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(ARCHIVES)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(ARCHIVES) -o $(NAME)

$(ARCHIVES):
	$(MAKE) -C .minilibx-linux/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: all clean fclean re
