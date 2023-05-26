/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:13:17 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/24 03:45:28 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_number_of_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (((s[i] != c) && i == 0) || ((s[i] != c) && (s[i - 1] == c)))
			count ++;
		i ++;
	}
	return (count);
}

static char	*extract_word(const char *str, char c, int *index)
{
	char		*word;
	const char	*s;
	int			word_length;
	int			i;

	i = 0;
	s = &str[*index];
	while (s[i] != c && s[i] != '\0')
		i++;
	word_length = i + 1;
	word = (char *) malloc(word_length);
	if (!word)
		return (NULL);
	i = 0;
	while (i < word_length - 1)
	{
		word[i] = s[i];
		i++;
		(*index)++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		j;

	words = ft_number_of_words(s, c);
	tab = (char **) malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		tab[i] = extract_word(s, c, &j);
		i++;
	}
	tab[words] = NULL;
	return (tab);
}
