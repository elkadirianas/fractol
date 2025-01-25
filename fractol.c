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

	if (((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
				&& !ft_strncmp(argv[1], "julia", 5))))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx_connection);
		printf("good");
	}
	else
	{
		printf("issa hh");
	}
	return (0);
}
