CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDE = -I fract_ol.h -L libft/ -lft mlx/libmlx_Linux.a -L mlx -lXext -lX11 -lm

SRCS = src/fract_ol.c \
	src/mandelbrot.c \
	src/color_conv.c \
	src/zoom.c src/julia.c \
	src/parsing.c \
	src/burning_ship.c \
	src/mandelbar.c \
	src/perpendicular_burning_ship.c

OBJS = $(SRCS:.c=.o)

NAME = fract-ol

all: $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	make -C libft/
	make -C mlx/
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
