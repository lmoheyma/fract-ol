CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDE = -I fract_ol.h -L libft/ -lft mlx/libmlx_Linux.a -L mlx -lXext -lX11 -lm -O3

SRCS = fract_ol.c mandelbrot.c color_conv.c zoom.c julia.c \
	parsing.c burning_ship.c mandelbar.c

OBJS = $(SRCS:.c=.o)

NAME = fract-ol

all: $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	make -C libft/
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
