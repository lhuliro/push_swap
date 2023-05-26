/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 04:32:41 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 07:43:14 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	run_command(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	if (!ft_strcmp(cmd, "pa\n"))
		pa(stack_a, stack_b, false);
	else if (!ft_strcmp(cmd, "pb\n"))
		pb(stack_b, stack_a, false);
	else if (!ft_strcmp(cmd, "sa\n"))
		sa(stack_a, false);
	else if (!ft_strcmp(cmd, "sb\n"))
		sb(stack_b, false);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss(stack_a, stack_b, false);
	else if (!ft_strcmp(cmd, "ra\n"))
		ra(stack_a, false);
	else if (!ft_strcmp(cmd, "rb\n"))
		rb(stack_b, false);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr(stack_a, stack_b, false);
	else if (!ft_strcmp(cmd, "rra\n"))
		rra(stack_a, false);
	else if (!ft_strcmp(cmd, "rrb\n"))
		rrb(stack_b, false);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr(stack_a, stack_b, false);
	else
		display_error("Error\n", 1);
}

void	get_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strcmp(line, "\n") == 0)
			break ;
		run_command(stack_a, stack_b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	if (is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
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
	get_instructions(stack_a, stack_b);
	free(numbers);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
