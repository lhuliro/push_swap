/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:06:32 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/25 00:51:18 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_char_to_digit(char c)
{
	int	d;

	d = 0;
	if (ft_isdigit(c))
		d = c - 48;
	return (d);
}

static int	ft_is_space(int c)
{
	if (c == '\r' || c == '\t' || c == ' '
		|| c == '\f' || c == '\v' || c == '\n')
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int64_t	ft_atoi(const char *str)
{
	int64_t	number;
	int32_t	sign;
	int		i;

	number = 0;
	sign = 1;
	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + ft_char_to_digit(str[i]);
		i++;
	}
	return (number * sign);
}
