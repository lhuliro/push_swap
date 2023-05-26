/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 02:51:51 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	selection_sort(int tab[], int size)
{
	int	min_index;
	int	step;
	int	i;

	step = 0;
	while (step < size - 1)
	{
		min_index = step;
		i = step + 1;
		while (i < size)
		{
			if (tab[i] < tab[min_index])
				min_index = i;
			i++;
		}
		if (min_index != step)
			swap2(&tab[min_index], &tab[step]);
		step++;
	}
}
