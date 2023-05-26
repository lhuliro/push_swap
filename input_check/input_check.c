/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:07:36 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_number(char *value)
{
	bool	answer;
	int		i;

	i = 0;
	answer = true;
	if (ft_is_sign(value[i]) && value[i + 1] != '\0')
		i++;
	while (value[i] && ft_isdigit(value[i]))
		i++;
	if (value[i] != '\0' && !ft_isdigit(value[i]))
		answer = false;
	return (answer);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_tab(char	**tab)
{
	int	i;
	int	size;

	i = 0;
	size = tab_size(tab);
	while (i < size)
		free(tab[i++]);
	free(tab);
	*tab = NULL;
}

int	count_values(int argc, char	**argv)
{
	char	**args;
	int		num_values;
	int		i;

	i = 1;
	num_values = 0;
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		num_values += tab_size(args);
		if (args)
			free_tab(args);
		i++;
	}
	return (num_values);
}

char	**get_values(int argc, char **argv)
{
	char	**values;
	char	**args;
	int		num_values;
	int		i;
	int		j;

	num_values = count_values(argc, argv);
	values = (char **) malloc(sizeof(char *) * (num_values + 1));
	if (!values)
		return (NULL);
	i = 0;
	while (i < num_values)
	{
		args = ft_split(*(++argv), ' ');
		j = 0;
		while (j < tab_size(args))
			values[i++] = args[j++];
	}
	values[num_values] = NULL;
	return (values);
}
