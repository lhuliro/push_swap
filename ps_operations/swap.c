/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:18:00 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	t_stack_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
}

void	sa(t_stack *stack_a, bool write)
{
	swap(stack_a);
	if (write)
		ft_putstr("sa\n");
}

void	sb(t_stack *stack_b, bool write)
{
	swap(stack_b);
	if (write)
		ft_putstr("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, bool write)
{
	swap(stack_a);
	swap(stack_b);
	if (write)
		ft_putstr("ss\n");
}
