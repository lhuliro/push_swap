# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuliro- <lhuliro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 19:24:46 by lhuliro-          #+#    #+#              #
#    Updated: 2023/05/24 08:22:15 by lhuliro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS		=	checker
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -I$(INC_DIR)

HFILES		=	push_swap.h 
LIBFT		=	libft/
LIB			=	lib/
S_ALGS		=	sorting_algorithms/
MOVES		=	ps_operations/
SORT		=	sort_stack/
INPUT_CHECK	=	input_check/
OUTDIR		=	obj
INC_DIR		=	includes/
BSRCS		=	bonus/

SRC			=	$(S_ALGS)bubble_sort.c $(S_ALGS)selection_sort.c $(S_ALGS)binary_search.c $(S_ALGS)insertion_sort.c \
				$(LIBFT)ft_atoi.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_putstr.c $(LIBFT)ft_split.c $(LIBFT)ft_strlen.c \
				$(MOVES)swap.c $(MOVES)push.c $(MOVES)rotate.c $(MOVES)reverse_rotate.c \
				$(SORT)sort.c $(SORT)sort_utils.c \
				$(INPUT_CHECK)input_check.c $(INPUT_CHECK)input_check2.c \
				stack_utils.c \
				push_swap.c \
				
SRC_BONUS	=	$(BSRCS)checker.c $(BSRCS)get_next_line.c\
				$(S_ALGS)bubble_sort.c $(S_ALGS)selection_sort.c $(S_ALGS)binary_search.c $(S_ALGS)insertion_sort.c \
				$(MOVES)swap.c $(MOVES)push.c $(MOVES)rotate.c $(MOVES)reverse_rotate.c \
				$(INPUT_CHECK)input_check.c $(INPUT_CHECK)input_check2.c \
				$(LIBFT)ft_atoi.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_putstr.c $(LIBFT)ft_split.c $(LIBFT)ft_strlen.c $(LIBFT)ft_strcmp.c \
				$(SORT)sort.c $(SORT)sort_utils.c \
				stack_utils.c \

OBJ			= 	$(SRC:%.c=$(OUTDIR)/%.o)
OBJ_BONUS	=	$(SRC_BONUS:%.c=$(OUTDIR)/%.o)

$(OUTDIR)/%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)	#final compilation
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)	#final compilation
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

fclean: clean
	@rm -rf $(NAME) $(BONUS)

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)

re: fclean all bonus

.PHONY: all fclean clean re