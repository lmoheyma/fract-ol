/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:03:13 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/01/28 18:31:22 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

void	zoom(t_fractal *fractal, int x, int y)
{
	double	zoom_exp;

	zoom_exp = 1.5;
	fractal->x1 = (x / fractal->zoom + fractal->x1) - (x / (fractal->zoom
				* zoom_exp));
	fractal->y1 = (y / fractal->zoom + fractal->y1) - (y / (fractal->zoom
				* zoom_exp));
	fractal->zoom *= zoom_exp;
}

void	dezoom(t_fractal *fractal, int x, int y)
{
	double	zoom_exp;

	zoom_exp = 1.5;
	fractal->x1 = (x / fractal->zoom + fractal->x1) - (x / (fractal->zoom
				/ zoom_exp));
	fractal->y1 = (y / fractal->zoom + fractal->y1) - (y / (fractal->zoom
				/ zoom_exp));
	fractal->zoom /= zoom_exp;
}
