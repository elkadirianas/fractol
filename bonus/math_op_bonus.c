/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:47:30 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/25 19:47:35 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	scale(double number, double n_min, double n_max, double o_max)
{
	return ((n_max - n_min) * (number) / (o_max) + n_min);
}

t_complex	sum_complex(t_complex num_1, t_complex num_2)
{
	t_complex	result;

	result.r = num_1.r + num_2.r;
	result.i = num_1.i + num_2.i;
	return (result);
}

t_complex	square_complex(t_complex num)
{
	t_complex	result;

	result.r = num.r * num.r - num.i * num.i;
	result.i = 2 * num.r * num.i;
	return (result);
}
