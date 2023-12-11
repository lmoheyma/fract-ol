/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 01:57:05 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/11 14:00:18 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	draw_julia(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			julia(fractal);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0.0;
	}
	return (0);
}

void	julia(t_fractal *fractal)
{
	int	i;

	i = 0;
	fractal->zx = fractal->x / fractal->zoom + fractal->x1;
	fractal->zy = fractal->y / fractal->zoom + fractal->y1;
	while (fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4
		&& i < fractal->max_iter)
	{
		fractal->tempx = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * fractal->tempx + fractal->cy;
		i++;
	}
	if (i == fractal->max_iter)
		color_pixel(fractal, fractal->x, fractal->y, 000000);
	else
		color_pixel(fractal, fractal->x, fractal->y, rgb(fractal->zoom / (i
					* 2), (i * 255 / fractal->zoom), (fractal->zoom - pow(i,
						2))));
}
