/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:00:22 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/10 05:00:25 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int close_window(void)
{
	// mlx_destroy_display(fractal.ptr);
	// free(fractal.ptr);
	exit(0);
}

int mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	if (mousecode == 4)
		zoom(fractal, x, y);
	else if (mousecode == 5)
		dezoom(fractal, x, y);
	choose_fractal(fractal->id, fractal);
	return (0);
}

int key_hook(int keycode, t_fractal *fractal, char *fractal_name)
{
	if (keycode == KEY_ESC)
		close_window();
	else if (keycode == KEY_UP_ARROW)
		fractal->y1 -= 80 / fractal->zoom;
	else if (keycode == KEY_LEFT_ARROW)
		fractal->x1 -= 80 / fractal->zoom;
	else if (keycode == KEY_DOWN_ARROW)
		fractal->y1 += 80 / fractal->zoom;
	else if (keycode == KEY_RIGHT_ARROW)
		fractal->x1 += 80 / fractal->zoom;
	choose_fractal(fractal->id, fractal);
	return (0);
}

void fractal_init(t_fractal *fractal, char *id)
{
	fractal->id = id;
	fractal->x1 = -2.1;
	fractal->y1 = -1.2;
	fractal->zoom = 300;
	fractal->max_iter = MAX_ITER;
	fractal->iter_red = 100;
	fractal->iter_blue = 1000;
	fractal->iter_green = 10000;
}

int main(int argc, char **argv)
{	
	t_fractal	fractal;

	if (parsing(argc, argv))
		return (0);
	fractal_init(&fractal, argv[1]);
	fractal.ptr = mlx_init();
	if (!fractal.ptr)
		return (0);
	fractal.window = mlx_new_window(fractal.ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!fractal.window)
	{
		free(fractal.window);
		return (1);
	}
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, 17, 0L, close_window, fractal.ptr);
	choose_fractal(argv[1], &fractal);
	mlx_loop(fractal.ptr);
	//free 
}
