/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:25:27 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	current = stack->head;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}	

void	ra(t_stack *stack_a, bool write)
{
	rotate(stack_a);
	if (write)
		ft_putstr("ra\n");
}

void	rb(t_stack *stack_b, bool write)
{
	rotate(stack_b);
	if (write)
		ft_putstr("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, bool write)
{
	rotate(stack_a);
	rotate(stack_b);
	if (write)
		ft_putstr("rr\n");
}
