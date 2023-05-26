/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:29:53 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack *dest, t_stack *src)
{
	if (src->head == NULL)
		return ;
	push_stack(dest, pop_stack(src));
}

void	pa(t_stack *stack_a, t_stack *stack_b, bool write)
{
	push(stack_a, stack_b);
	if (write)
		ft_putstr("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a, bool write)
{
	push(stack_b, stack_a);
	if (write)
		ft_putstr("pb\n");
}
