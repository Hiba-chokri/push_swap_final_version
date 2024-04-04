/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:10:04 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 14:51:40 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_target_pos(int target, t_stack *b)
{
	int	size;
	int	i;

	size = ft_lstsize(b);
	i = 0;
	while (b != NULL)
	{
		if (b->data == target)
			break ;
		i++;
		b = b->next;
	}
	return (i <= size / 2);
}

void	calculate_best_target(t_stack **a, t_stack **b, long *best_target,
		int *node)
{
	long	target;
	long	cost;
	long	min_cost;
	t_stack	*current;

	current = *a;
	min_cost = LONG_MAX;
	while (current != NULL)
	{
		target = find_target(current->data, *b);
		if (target == LONG_MIN)
			target = find_max(b);
		cost = calculate_cost(*a, *b, current->data, target);
		if (cost < min_cost)
		{
			*best_target = target;
			min_cost = cost;
			*node = current->data;
		}
		current = current->next;
	}
}

void	rotate_to_best_target(t_stack **a, t_stack **b, int best_target,
		int node)
{
	int	above_target;
	int	above_node;

	above_target = check_target_pos(best_target, *b);
	above_node = check_node_pos(node, *a);
	if (above_target == 1 && above_node == 1)
	{
		while (best_target != (*b)->data && node != (*a)->data)
			ft_rotate(a, b);
	}
	else if (above_target == 0 && above_node == 0)
	{
		while (best_target != (*b)->data && node != (*a)->data)
			rrr(a, b);
	}
}

void	adjust_stacks(t_stack **a, t_stack **b, int best_target, int node)
{
	int	above_target;
	int	above_node;

	above_target = check_target_pos(best_target, *b);
	above_node = check_node_pos(node, *a);
	if (above_target == 1)
	{
		while (best_target != (*b)->data)
			rotate_b(b, 1);
	}
	else
	{
		while (best_target != (*b)->data)
			rrb(b);
	}
	if (above_node == 1)
		while (node != (*a)->data)
			rotate_a(a, 1);
	else
	{
		while (node != (*a)->data)
			rra(a);
	}
}

void	from_a_to_b(t_stack **a, t_stack **b)
{
	long	best_target;
	int		node;

	best_target = LONG_MIN;
	node = (*a)->data;
	calculate_best_target(a, b, &best_target, &node);
	rotate_to_best_target(a, b, best_target, node);
	adjust_stacks(a, b, best_target, node);
	push_b(a, b);
}
