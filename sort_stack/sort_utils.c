/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:53:04 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_stack_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	get_highest_index(t_stack *stack)
{
	t_stack_node	*tmp;
	int				index;

	tmp = stack->head;
	index = tmp->final_index;
	while (tmp)
	{
		if (tmp->final_index > index)
			index = tmp->final_index;
		tmp = tmp->next;
	}
	return (index);
}

int	get_min_index(t_stack *stack)
{
	t_stack_node	*current;
	int				min_index;

	current = stack->head;
	min_index = current->final_index;
	while (current->next)
	{
		current = current->next;
		if (current->final_index < min_index)
			min_index = current->final_index;
	}
	return (min_index);
}

int	count_rotations(t_stack_node *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->final_index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}
