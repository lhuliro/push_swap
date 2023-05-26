/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:52:46 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 09:47:02 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack *stack)
{
	t_stack_node	*tmp;
	int				highest_index;

	tmp = stack->head;
	if (!is_sorted(stack))
	{
		highest_index = get_highest_index(stack);
		if (tmp->final_index == highest_index)
			ra(stack, true);
		else if (tmp->next->final_index == highest_index)
			rra(stack, true);
		tmp = stack->head;
		if (tmp->next && (tmp->final_index > tmp->next->final_index))
			sa(stack, true);
	}
}

void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = stack_a->size;
	while (iter++ < n - 3)
	{
		min_index = get_min_index(stack_a);
		if (count_rotations(stack_a->head, min_index) <= n - min_index - \
			count_rotations(stack_a->head, min_index))
			while (stack_a->head->final_index != min_index)
				ra(stack_a, true);
		else
			while (stack_a->head->final_index != min_index)
				rra(stack_a, true);
		if (is_sorted(stack_a) && stack_b->size == 0)
			return ;
		pb(stack_b, stack_a, true);
	}
	sort_3(stack_a);
	iter = 0;
	while (iter++ < n - 3)
		pa(stack_a, stack_b, true);
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	length = stack_a->size;
	while (stack_a->head)
	{
		if (stack_a->head->final_index <= i)
		{
			pb(stack_b, stack_a, true);
			rb(stack_b, true);
			i++;
		}
		else if (stack_a->head->final_index <= i + range)
		{
			pb(stack_b, stack_a, true);
			i++;
		}
		else
			ra(stack_a, true);
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_rotations(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->final_index != length - 1)
				rb(stack_b, true);
			pa(stack_a, stack_b, true);
			length--;
		}
		else
		{
			while (stack_b->head->final_index != length - 1)
				rrb(stack_b, true);
			pa(stack_a, stack_b, true);
			length--;
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	length;

	length = stack_a->size;
	if (is_sorted(stack_a))
		return ;
	else if (length == 2)
		sa(stack_a, true);
	else if (length == 3)
		sort_3(stack_a);
	else if (length <= 7)
		s_insertion_sort(stack_a, stack_b);
	else if (length > 7)
	{
		k_sort1(stack_a, stack_b, length);
		k_sort2(stack_a, stack_b, length);
	}
	else
		display_error("", 1);
}
