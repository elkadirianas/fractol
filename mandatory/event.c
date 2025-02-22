/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:42:23 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/25 19:42:46 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	close_f(void)
{
	exit(0);
	return (0);
}

int	key_handle(int keycode, t_fractal *fractal)
{
	if (keycode == ESCAPE)
		close_f();
	else if (keycode == PLUS)
		fractal->iterations += 10;
	else if (keycode == MINUS)
		fractal->iterations -= 10;
	render(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	x = 0;
	y = 0;
	if (button == MOUSE_UP)
		fractal->zoom *= 1.05;
	else if (button == MOUSE_DOWN)
		fractal->zoom *= 0.95;
	render(fractal);
	return (x + y);
}
