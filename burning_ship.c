//HEADER

#include "fract-ol.h"

int draw_burning_ship(t_fractal *fractal)
{
	fractal->x = 0.0;
	fractal->y = 0.0;
	
	while (fractal->y < HEIGHT)
	{
		while (fractal->x < WIDTH)
		{
			burning_ship(fractal);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0.0;
	}
	return (0);
}

void burning_ship(t_fractal *fractal)
{
	int i;

	i = 0;
    fractal->zx = 0.0;
    fractal->zy = 0.0;
	fractal->cx = fractal->x / fractal->zoom + fractal->x1;
	fractal->cy = fractal->y / fractal->zoom + fractal->y1;
	while (fractal->zx * fractal->zx + fractal->zy * fractal->zy < 4
		&& i < fractal->max_iter)
	{
		fractal->tempx = fractal->zx * fractal->zx - fractal->zy * fractal->zy + fractal->cx;
		fractal->zx = fabs(2.0 * fractal->zx * fractal->zy) + fractal->cy;
		fractal->zy = fabs(fractal->tempx);
		i++;
	}
	if (i == fractal->max_iter)
		mlx_pixel_put(fractal->ptr, fractal->window, fractal->x, fractal->y, 0x000000);
	else
		mlx_pixel_put(fractal->ptr, fractal->window, fractal->x, fractal->y, rgb(i * 10, i * 255 / fractal->max_iter, 0));
}