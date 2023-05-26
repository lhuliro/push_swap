/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:21:38 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/25 00:29:59 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b,
		int *values, int tab_size)
{
	int				size;
	t_stack_node	*tmp;

	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	size = tab_size - 1;
	while (size >= 0)
	{
		tmp = new_node(values[size]);
		if (!tmp)
			return ;
		push_stack(stack_a, tmp);
		size--;
	}
	insertion_sort(values, tab_size);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->final_index = classic_search(tmp->value, values);
		tmp = tmp->next;
	}
}

void	display_error(char *error_msg, bool b)
{
	write(2, error_msg, ft_strlen(error_msg));
	if (b == true)
		exit(EXIT_FAILURE);
}

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**values;
	int		*numbers;
	int		num_values;

	if (argc == 1)
		return (0);
	values = get_values(argc, argv);
	if (!check_valid_values(values))
		display_error("Error\n", 1);
	num_values = tab_size(values);
	numbers = get_numeric_values(values);
	if (exist_duplicates(numbers, num_values))
		display_error("Error\n", 1);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	init_stack(stack_a, stack_b, numbers, num_values);
	sort(stack_a, stack_b);
	free(numbers);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
