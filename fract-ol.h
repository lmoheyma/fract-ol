/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:50:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 05:37:28 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 1280
# define HEIGHT 720
# define MAX_ITER 45
# define KEY_ESC 65307
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364

typedef struct s_fractal
{
	void			*ptr;
	void			*window;
	char			*id;
	double			x;
	double			y;
	double			zoom;
	double			x1;
	double			y1;
	double			zx;
	double			zy;
	double			cx;
	double			cy;
	double			tempx;
	int				max_iter;
	int				iter_red;
	int				iter_blue;
	int				iter_green;
}					t_fractal;

typedef struct s_pixeltab
{
	int				pixels_red[WIDTH][HEIGHT];
	int				pixels_blue[WIDTH][HEIGHT];
	int				pixels_green[WIDTH][HEIGHT];
}					t_pixeltab;

typedef struct s_tmplst
{
	int				x;
	int				y;
	struct s_tmplst	*next;
}					t_tmplst;

// Init
void				fractal_init(t_fractal *fractal, char *id);

// Window
int					key_hook(int keycode, t_fractal *fractal,
						char *fractal_name);
int					mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int					close_window(void);

// Parsing
int					parsing(int argc, char **argv);
void				choose_fractal(char *argv, t_fractal *fractal);

// Mandelbrot
int					draw_mandelbrot(t_fractal *fractal);
void				mandelbrot(t_fractal *fractal);

// Julia
int					draw_julia(t_fractal *fractal);
void				julia(t_fractal *fractal);

// Buddhabrot
int					draw_buddhabrot(t_fractal *fractal);
void				buddhabrot(t_fractal *fractal);

// Linked list
t_tmplst			*new_node(int x, int y);
void				add_node_back(t_tmplst **lst, t_tmplst *new);
t_tmplst			*lastnode(t_tmplst *lst);

// Colors
int					rgb(unsigned char r, unsigned char g, unsigned char b);

// Zoom
void				zoom(t_fractal *fractal, int x, int y);
void				dezoom(t_fractal *fractal, int x, int y);

#endif