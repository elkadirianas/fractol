/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkadir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:59:12 by aelkadir          #+#    #+#             */
/*   Updated: 2025/01/26 23:59:14 by aelkadir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	double_signe_dots(char *str)
{
	int	i;
	int	count_s;
	int	count_d;

	i = 0;
	count_s = 0;
	count_d = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			count_s++;
		if (str[i] == '.')
			count_d++;
		if (count_d > 1 || count_s > 1)
			return (1);
		i++;
	}
	return (0);
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
