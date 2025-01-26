/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:45:07 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/25 19:45:11 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	event_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KEYPRESS, 0, key_handle, fractal);
	mlx_hook(fractal->mlx_window, BUTTONPRESS, 0, mouse_handle, fractal);
	mlx_hook(fractal->mlx_window, DESTROYNOTIFY, 0, close_f, fractal);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		exit(1);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, W, H,
			fractal->name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		free(fractal->mlx_window);
		exit(1);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, W, H);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		free(fractal->mlx_window);
		exit(1);
	}
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_length,
			&fractal->img.endian);
	event_init(fractal);
	data_init(fractal);
}
