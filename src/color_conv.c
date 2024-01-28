/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:05:30 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/01/28 18:31:03 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buf;

	buf = fractal->data_addr;
	buf[(y * fractal->size_line / 4) + x] = color;
}

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

double	smooth_color(int i, double zx, double zy)
{
	double	n_smooth;

	n_smooth = log(log(sqrt(zx * zx + zy * zy))) / log(2.0);
	if (i == MAX_ITER)
		return (MAX_ITER);
	return (i + 1 - n_smooth);
}

t_rgb	smooth_to_rgb(double smooth_color)
{
	t_rgb	c;

	c.r = (int)(smooth_color * 100) % 256;
	c.g = (int)(smooth_color * 20) % 256;
	c.b = (int)(smooth_color * 200) % 256;
	return (c);
}
