/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoheyma <lmoheyma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:00:22 by lmoheyma          #+#    #+#             */
/*   Updated: 2023/12/08 15:56:21 by lmoheyma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fract-ol.h"

int close(t_data *data)
{
	mlx_destroy_window(data->ptr, data->window);
	return (0);
}

int main()
{	
	t_data data;

	data.ptr = mlx_init();
	data.window = mlx_new_window(data.ptr, 1920, 1080, "Fract-ol");
	// check ptr not null
	mlx_hook(data.window, 2, 1L<<0, close, &data);
	mlx_loop(data.ptr);
	//free 
}