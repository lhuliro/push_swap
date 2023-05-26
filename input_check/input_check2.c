/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:30:30 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/25 01:05:49 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*get_numeric_values(char **values)
{
	int	*tab;
	int	size;
	int	i;

	size = tab_size(values);
	i = 0;
	tab = (int *) malloc(sizeof(int) * (size + 1));
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = ft_atoi(values[i]);
		i++;
	}
	return (tab);
}

bool	is_int(char *value)
{
	if (ft_atoi(value) > INT_MAX \
			|| ft_atoi(value) < INT_MIN \
			|| ft_strlen(value) > 11)
		return (false);
	return (true);
}

bool	check_valid_values(char **values)
{
	int		num_values;
	int		i;

	num_values = tab_size(values);
	i = 0;
	while (i < num_values)
	{
		if (!is_number(values[i]) || !is_int(values[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	exist_duplicates(int *numbers, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
