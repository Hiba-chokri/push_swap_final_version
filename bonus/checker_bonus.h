/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:43:41 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 00:37:27 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// # include "./includes/libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "../push_swap.h"


// typedef struct s_stack 
// {
// 	int data;
// 	struct s_stack *next;
// } t_stack;

void	swap_a_bonus(t_stack **top);
void	swap_b_bonus(t_stack **top);
void	rotate_a_bonus(t_stack **top);
void	rotate_b_bonus(t_stack **top);
void	ft_rotate_bonus(t_stack **a, t_stack **b);
void	rrr_bonus(t_stack **a, t_stack **b);
void	ft_ss_bonus(t_stack **a, t_stack **b);
void	ft_reverse_rotate_bonus(t_stack **top);
void	handling_errors(char *line, t_stack **a, t_stack **stack_b);
void	rra(t_stack **top);
void	rrb(t_stack **top);
void	push_a_bonus(t_stack **a, t_stack **b);
void	push_b_bonus(t_stack **a, t_stack **b);
void	ft_split_args2(t_stack **a, int argc, char *argv[]);
int	is_stack_sorted1(t_stack *a);
int	check_arg1(char **argv);
void	execute_command(char *line, t_stack **a, t_stack **b);
void	checker(t_stack **a, t_stack **b);
int	check_double1(t_stack *a);
int	check1(char *argv[]);
void	free_error1(t_stack **a);
int	free_stack1(t_stack **x);
int	is_not_integer1(char *argv[]);
int	count_spaces1(char *argv[]);
#endif