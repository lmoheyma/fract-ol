/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:01:02 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 05:46:31 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	max_3(int red, int blue, int green)
{
	if (red >= blue && red >= green)
		return (red);
	else if (blue >= red && blue >= green)
		return (blue);
	return (green);
}

int	draw_buddhabrot(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	fractal->max_iter = max_3(fractal->iter_red, fractal->iter_blue,
			fractal->iter_green);
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			buddhabrot(fractal);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0.0;
	}
	return (0);
}

void	buddhabrot(t_fractal *fractal)
{
	int			i;
	int			j;
	t_tmplst	*lst;
	t_pixeltab	tab;

	lst = NULL;
	i = 0;
	j = 0;
	fractal->cx = fractal->x / fractal->zoom + fractal->x1;
	fractal->cy = fractal->y / fractal->zoom + fractal->y1;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	while (fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4
		&& i < fractal->max_iter)
	{
		fractal->tempx = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * fractal->tempx + fractal->cy;
		i++;
		add_node_back(&lst, new_node((fractal->zx - fractal->x1) * fractal->zoom,
				(fractal->zy - fractal->y1) * fractal->zoom));
	}
	if (i < fractal->iter_red)
	{
		// while (lst && j < fractal->iter_red)
		// {
		// 	if (tab.pixels_red[i][j])
		// }
	}
		// mlx_pixel_put(fractal->ptr, fractal->window, fractal->x, fractal->y,
		// 	0x000000);
	else
	{
		mlx_pixel_put(fractal->ptr, fractal->window, fractal->x, fractal->y,
			rgb(0, 0, i * 255 / MAX_ITER));
	}
}
