/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 02:51:17 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap2(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int tab[], int size)
{
	bool	swapped;
	int		step;
	int		i;

	swapped = true;
	step = 0;
	while (step < size - 1 && swapped)
	{
		swapped = false;
		i = 0;
		while (i < size - step - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap2(&tab[i], &tab[i + 1]);
				swapped = true;
			}
			i++;
		}
		step++;
	}
}
