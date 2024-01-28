/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:00:46 by lmoheyma          #+#    #+#             */
/*   Updated: 2024/01/28 18:31:16 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract_ol.h"

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
	else if (ft_strncmp("Mandelbar", str, 10) == 0)
		draw_mandelbar(fractal);
	else if (ft_strncmp("PerBurningShip", str, 15) == 0)
		draw_p_burning_ship(fractal);
	mlx_put_image_to_window(fractal->ptr, fractal->window, fractal->image, 0,
		0);
	return (0);
}

int	available_fractal(void)
{
	write(1, "Available : \n", 14);
	write(1, "-> Mandelbrot\n", 15);
	write(1, "-> Julia\n", 10);
	write(1, "-> BurningShip\n", 16);
	write(1, "-> Mandelbar\n", 14);
	write(1, "-> PerBurningShip\n", 19);
	return (1);
}

int	parsing(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Not enough arguments\n", 22);
		return (available_fractal());
	}
	else if (argc > 2)
	{
		write(1, "Too much arguments\n", 20);
		return (available_fractal());
	}
	else if (ft_strncmp("Mandelbrot", argv[1], 12) != 0 && ft_strncmp("Julia",
			argv[1], 5) != 0 && ft_strncmp("BurningShip", argv[1], 12) != 0
		&& ft_strncmp("Mandelbar", argv[1], 10) != 0
		&& ft_strncmp("PerBurningShip", argv[1], 15) != 0)
	{
		write(1, "Invalid arguments\n", 19);
		return (available_fractal());
	}
	else
		return (0);
}
