/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:00:46 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 16:56:37 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	choose_fractal(char *argv, t_fractal *fractal)
{
	if (ft_strncmp("Mandelbrot", argv, 12) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp("Julia", argv, 5) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.8;
			fractal->cy = 0.156;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp("BurningShip", argv, 12) == 0)
		draw_burning_ship(fractal);
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (argc < 2)
		return (write(1,
				"Not enough arguments\nAvailable fractal :\n-> Mandelbrot\n-> Julia\n-> BurningShip\n",
				80));
	else if (argc > 2)
		return (write(1,
				"Too much arguments\nAvailable fractal :\n-> Mandelbrot\n-> Julia\n-> BurningShip\n",
				78));
	else if (ft_strncmp("Mandelbrot", argv[1], 12) != 0 && ft_strncmp("Julia",
			argv[1], 5) != 0 && ft_strncmp("BurningShip", argv[1], 12) != 0)
		return (write(1,
				"Invalid arguments\nAvailable fractal :\n-> Mandelbrot\n-> Julia\n-> BurningShip\n",
				77));
	else
		return (0);
}
