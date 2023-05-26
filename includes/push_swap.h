/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:05:52 by lhuliro-          #+#    #+#             */
/*   Updated: 2023/05/25 01:01:02 by lhuliro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					final_index;
	struct s_stack_node	*next;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	int				size;
}					t_stack;

/* Stack utilities */
void			push_stack(t_stack *stack, t_stack_node *node);
t_stack_node	*pop_stack(t_stack *stack);
t_stack_node	*new_node(int value);
void			free_stack(t_stack *stack);
void			init_stack(t_stack *stack_a, t_stack *stack_b,
					int *values, int tab_size);

/* swap operations */
void			sa(t_stack *stack_a, bool write);
void			sb(t_stack *stack_b, bool write);
void			ss(t_stack *stack_a, t_stack *stack_b, bool write);

/* rotation operations */
void			ra(t_stack *stack_a, bool write);
void			rb(t_stack *stack_b, bool write);
void			rr(t_stack *stack_a, t_stack *stack_b, bool write);

/* reverse rotation operations */
void			rra(t_stack *stack_a, bool write);
void			rrb(t_stack *stack_b, bool write);
void			rrr(t_stack *stack_a, t_stack *stack_b, bool write);

/* push operations */
void			pa(t_stack *stack_a, t_stack *stack_b, bool write);
void			pb(t_stack *stack_b, t_stack *stack_a, bool write);

/* Input check */

int				tab_size(char **tab);
void			free_tab(char	**tab);
int				count_values(int argc, char	**argv);
char			**get_values(int argc, char **argv);

bool			is_int(char *value);
bool			is_number(char *value);
bool			check_valid_values(char **values);

int				*get_numeric_values(char **values);
bool			exist_duplicates(int *numbers, int size);
void			display_error(char *error_msg, bool b);

/* Sorting algorithms */

void			swap2(int *a, int *b);
void			bubble_sort(int tab[], int size);
void			selection_sort(int tab[], int size);
void			insertion_sort(int tab[], int size);
int				binary_search(int key, int *sorted_tab, int low, int high);
int				classic_search(int key, int *tab);

/* libft */

void			ft_putchar(char c);
void			ft_putstr(char *s);
char			**ft_split(const char *s, char c);
int64_t			ft_atoi(const char *str);
int				ft_is_sign(char c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_sqrt(int number);
int				ft_strcmp(char *str_1, char *str_2);

/* Sort */

void			sort(t_stack *stack_a, t_stack *stack_b);
bool			is_sorted(t_stack *stack);
int				get_highest_index(t_stack *stack);
int				get_min_index(t_stack *stack);
int				count_rotations(t_stack_node *stack, int index);

#endif