/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:03:13 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 01:54:21 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void zoom(t_fractal *fractal, int x, int y)
{
	double	zoom_exp;

	zoom_exp = 1.5;
	fractal->x1 = (x / fractal->zoom + fractal->x1) - (x / (fractal->zoom * zoom_exp));
	fractal->y1 = (y / fractal->zoom + fractal->y1) - (y / (fractal->zoom * zoom_exp));	
	fractal->zoom *= zoom_exp;
}

void dezoom(t_fractal *fractal, int x, int y)
{
	double	zoom_exp;

	zoom_exp = 1.5;
	fractal->x1 = (x / fractal->zoom + fractal->x1) - (x / (fractal->zoom / zoom_exp));
	fractal->y1 = (y / fractal->zoom + fractal->y1) - (y / (fractal->zoom / zoom_exp));	
	fractal->zoom /= zoom_exp;
}