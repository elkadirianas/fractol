/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:54:52 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/25 19:54:54 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_atodouble(char *str)
{
	int		i;
	int		signe;
	double	power;
	double	res;

	i = 0;
	res = 0;
	power = 1;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (('0' <= str[i] && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		power = power / 10;
		res = res + (str[i] - '0') * power;
		i++;
	}
	return (res * signe);
}

int	is_empty(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	check_char(char str)
{
	return ((str >= '0' && str <= '9') || str == '.' || str == '+' || str == '-'
		|| str == ' ' || (str >= 9 && str <= 13));
}

int	contains_invalid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(char *str)
{
	size_t	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
		i++;
	if (str[i] == '.')
	{
		if (i == 0)
			return (0);
		if (!('0' <= str[i - 1] && str[i - 1] <= '9') || !('0' <= str[i + 1]
				&& str[i + 1] <= '9'))
			return (0);
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9'))
		i++;
	if (double_signe(str) || !contains_invalid(str) || is_empty(str)
		|| !ft_strcmp(str, "-") || !ft_strcmp(str, "+"))
		return (0);
	return (1);
}
