/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:35:39 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack->head || !stack->head->next || !stack)
		return ;
	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
}

void	rra(t_stack *stack_a, bool write)
{
	reverse_rotate(stack_a);
	if (write)
		ft_putstr("rra\n");
}

void	rrb(t_stack *stack_b, bool write)
{
	reverse_rotate(stack_b);
	if (write)
		ft_putstr("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, bool write)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (write)
		ft_putstr("rrr\n");
}
