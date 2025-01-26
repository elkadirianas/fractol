/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:43:44 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/25 19:43:46 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (((argc == 2 && !ft_strcmp(argv[1], "mandelbrot")) || (argc == 4
				&& !ft_strcmp(argv[1], "julia"))))
	{
		fractal.name = argv[1];
		if (!ft_strcmp(fractal.name, "julia"))
		{
			if (!is_valid(argv[2]) || !is_valid(argv[3]))
			{
				ft_putstr_fd("wrong params, try julia c.i c.i", 1);
				return (0);
			}
			fractal.julia_x = ft_atodouble(argv[2]);
			fractal.julia_y = ft_atodouble(argv[3]);
		}
		fractal_init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_connection);
		printf("good");
	}
	else
		ft_putstr_fd("wrong params try mandelbrot or julia c.i c.i", 1);
	return (0);
}
