/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:00:46 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/11 03:44:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	choose_fractal(char *str, t_fractal *fractal)
{
	if (ft_strncmp("Mandelbrot", str, 12) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp("Julia", str, 5) == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.8;
			fractal->cy = 0.156;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp("BurningShip", str, 12) == 0)
		draw_burning_ship(fractal);
	mlx_put_image_to_window(fractal->ptr, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Not enough arguments\n", 22);
		return (write(1,
				"Available :\n-> Mandelbrot\n-> Julia\n-> BurningShip\n",
				51));
	}
	else if (argc > 2)
	{
		write(1, "Too much arguments\n", 20);
		return (write(1,
				"Available :\n-> Mandelbrot\n-> Julia\n-> BurningShip\n",
				51));
	}
	else if (ft_strncmp("Mandelbrot", argv[1], 12) != 0 && ft_strncmp("Julia",
			argv[1], 5) != 0 && ft_strncmp("BurningShip", argv[1], 12) != 0)
	{
		write(1, "Invalid arguments\n", 19);
		return (write(1,
				"Available :\n-> Mandelbrot\n-> Julia\n-> BurningShip\n",
				51));
	}
	else
		return (0);
}
