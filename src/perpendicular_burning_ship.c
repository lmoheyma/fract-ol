/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpendicular_burning_ship.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:48:29 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/01/28 18:31:20 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

int	draw_p_burning_ship(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			p_burning_ship(fractal);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0.0;
	}
	return (0);
}

void	p_burning_ship(t_fractal *fractal)
{
	int	i;

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
		fractal->zy = -2.0 * fractal->zx * fabs(fractal->zy) + fractal->cy;
		fractal->zx = fractal->tempx;
		i++;
	}
	if (i == fractal->max_iter)
		color_pixel(fractal, fractal->x, fractal->y, 000000);
	else
		color_pixel(fractal, fractal->x, fractal->y, rgb(fractal->zoom / (i
					* 2), (i * 255 / fractal->zoom), (fractal->zoom - pow(i,
						2))));
}
