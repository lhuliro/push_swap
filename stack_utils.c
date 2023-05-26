/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:38:15 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/25 00:15:02 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_stack(t_stack *stack, t_stack_node *node)
{
	node->next = stack->head;
	stack->head = node;
	stack->size++;
}

t_stack_node	*pop_stack(t_stack *stack)
{	
	t_stack_node	*top;

	if (!stack->head)
		return (NULL);
	top = stack->head;
	stack->head = top->next;
	stack->size--;
	return (top);
}

t_stack_node	*new_node(int value)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->final_index = 0;
	return (node);
}

void	free_stack(t_stack *stack)
{
	while (stack->head)
		free(pop_stack(stack));
	free(stack);
}
