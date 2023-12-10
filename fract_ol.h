/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:50:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 21:01:58 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1280
# define HEIGHT 720
# define MAX_ITER 50
# define KEY_ESC 65307
# define KEY_LEFT_ARROW 65361
# define KEY_UP_ARROW 65362
# define KEY_RIGHT_ARROW 65363
# define KEY_DOWN_ARROW 65364
# define KEY_Q 113
# define KEY_R 114

typedef struct s_fractal
{
	void	*ptr;
	void	*window;
	void	*image;
	void	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*id;
	double	x;
	double	y;
	double	zoom;
	double	x1;
	double	y1;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tempx;
	int		max_iter;
}			t_fractal;

// Init
void		fractal_init(t_fractal *fractal, char *id);

// Window
int			key_hook(int keycode, t_fractal *fractal, char *fractal_name);
int			mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int			close_window(void);

// Parsing
int			parsing(int argc, char **argv);
int			choose_fractal(char *argv, t_fractal *fractal);

// Mandelbrot
int			draw_mandelbrot(t_fractal *fractal);
void		mandelbrot(t_fractal *fractal);

// Julia
int			draw_julia(t_fractal *fractal);
void		julia(t_fractal *fractal);

// Burning Ship
int			draw_burning_ship(t_fractal *fractal);
void		burning_ship(t_fractal *fractal);

// Colors
void		color_pixel(t_fractal *fractal, int x, int y, int color);
int			rgb(int r, int g, int b);

// Zoom
void		zoom(t_fractal *fractal, int x, int y);
void		dezoom(t_fractal *fractal, int x, int y);

#endif