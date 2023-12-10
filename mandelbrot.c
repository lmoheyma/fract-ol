/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 01:56:47 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 02:14:37 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			mandelbrot(fractal);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0.0;
	}
	return (0);
}

void	mandelbrot(t_fractal *fractal)
{
	int i;

	i = 1;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->x1;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->y1;
	while (fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4
		&& i < fractal->max_iter)
	{
		fractal->tempx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = fractal->tempx;
		i++;
	}
	if (i == fractal->max_iter)
		mlx_pixel_put(fractal->ptr, fractal->window, fractal->x, fractal->y, 0x000000);
	else
		mlx_pixel_put(fractal->ptr, fractal->window, fractal->x, fractal->y, rgb(i*255 / MAX_ITER, 0, fractal->zoom / 330));
}
