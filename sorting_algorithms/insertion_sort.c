/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 02:52:30 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insertion_sort(int tab[], int size)
{
	int	step;
	int	i;
	int	key;

	step = 1;
	while (step < size)
	{
		key = tab[step];
		i = step - 1;
		while (key < tab[i] && i >= 0)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = key;
		step++;
	}
}
