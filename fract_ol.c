/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:00:22 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/11 03:46:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_window(t_fractal *fractal)
{
	//mlx_destroy_image(fractal->ptr, fractal->image);
	//mlx_destroy_window(fractal->ptr, fractal->window);
	// free(fractal->ptr);
	// free(fractal);
	exit(1);
}

int	mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	if (mousecode == 4)
		zoom(fractal, x, y);
	else if (mousecode == 5)
		dezoom(fractal, x, y);
	choose_fractal(fractal->id, fractal);
	return (0);
}

int	key_hook(int keycode, t_fractal *fractal, char *fractal_name)
{
	if (keycode == KEY_ESC)
		close_window(fractal);
	else if (keycode == KEY_UP_ARROW)
		fractal->y1 -= 80 / fractal->zoom;
	else if (keycode == KEY_LEFT_ARROW)
		fractal->x1 -= 80 / fractal->zoom;
	else if (keycode == KEY_DOWN_ARROW)
		fractal->y1 += 80 / fractal->zoom;
	else if (keycode == KEY_RIGHT_ARROW)
		fractal->x1 += 80 / fractal->zoom;
	// else if (keycode == KEY_Q && ft_strncmp(fractal->id, "Julia", 6))
	// 	fractal->cx += -0.08;
	// else if (keycode == KEY_R && ft_strncmp(fractal->id, "Julia", 6))
	// 	fractal->cy -= 0.005;
	choose_fractal(fractal->id, fractal);
	return (0);
}

void	fractal_init(t_fractal *fractal, char *id)
{
	fractal->id = id;
	fractal->x1 = -2.1;
	fractal->y1 = -1.2;
	fractal->zoom = 300;
	fractal->max_iter = MAX_ITER;
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (parsing(argc, argv))
		return (0);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (0);
	fractal_init(fractal, argv[1]);
	fractal->ptr = mlx_init();
	if (!fractal->ptr)
		return (0);
	fractal->window = mlx_new_window(fractal->ptr, WIDTH, HEIGHT, "Fract-ol");
	fractal->image = mlx_new_image(fractal->ptr, WIDTH, HEIGHT);
	fractal->data_addr = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, close_window, fractal->ptr);
	choose_fractal(argv[1], fractal);
	mlx_loop(fractal->ptr);
	free(fractal->ptr);
}
