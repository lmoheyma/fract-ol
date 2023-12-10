/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:05:30 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 21:02:03 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

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
