/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:24:11 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	binary_search2(int key, int *sorted_tab, int low, int high)
{
	int	mid;

	if (high >= low)
	{
		mid = low + (high - low) / 2;
		if (sorted_tab[mid] == key)
			return (mid);
		if (sorted_tab[mid] > key)
			return (binary_search2(key, sorted_tab, low, mid));
		else if (sorted_tab[mid] < key)
			return (binary_search2(key, sorted_tab, mid, high));
	}
	return (-1);
}

int	binary_search(int key, int *sorted_tab, int low, int high)
{
	int	mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (sorted_tab[mid] == key)
			return (mid);
		if (sorted_tab[mid] < key)
			low = mid + 1;
		else
			high = mid + 1;
	}
	return (-1);
}

int	classic_search(int key, int *tab)
{
	int	i;

	i = 0;
	while (tab[i] != key)
		i++;
	return (i);
}
