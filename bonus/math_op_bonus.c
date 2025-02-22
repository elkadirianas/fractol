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

t_complex	absolute_complex(t_complex z)
{
	t_complex	res;

	res.r = z.r;
	res.i = z.i;
	if (res.r < 0)
		res.r = -res.r;
	if (res.i < 0)
		res.i = -res.i;
	return (res);
}

int	contains_sign(char *str)
{
	size_t	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
