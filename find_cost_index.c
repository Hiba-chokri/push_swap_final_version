/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:06:57 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 15:11:21 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack *a, t_stack *b, int node, int target)
{
	int	cost;
	int	cost1;
	int	cost2;
	int	index_node;
	int	index_targ;

	cost = 0;
	index_node = find_index(a, node);
	index_targ = find_index(b, target);
	if (index_node <= ft_lstsize(a) / 2 && index_targ <= ft_lstsize(b) / 2)
		cost = ft_max(index_node, index_targ);
	else if (index_node > ft_lstsize(a) / 2 && index_targ > ft_lstsize(b) / 2)
	{
		cost1 = ft_lstsize(a) - index_node;
		cost2 = ft_lstsize(b) - index_targ;
		cost = ft_max(cost1, cost2);
	}
	else
	{
		if (index_node <= ft_lstsize(a) / 2 && index_targ > ft_lstsize(b) / 2)
			cost = index_node + (ft_lstsize(b) - index_targ);
		else
			cost = index_targ + (ft_lstsize(a) - index_node);
	}
	return (cost);
}

long	find_target(int node, t_stack *b)
{
	long	closest_target;
	t_stack	*current;

	closest_target = LONG_MIN;
	current = b;
	while (current != NULL)
	{
		if (node > current->data && current->data > closest_target)
			closest_target = current->data;
		current = current->next;
	}
	return (closest_target);
}

long	find_bigger_targ(t_stack *b)
{
	long	bigger;
	t_stack	*current;

	current = b;
	bigger = LONG_MIN;
	while (current != NULL)
	{
		if (current->data > bigger)
			bigger = current->data;
		current = current->next;
	}
	return (bigger);
}

int	check_node_pos(int node, t_stack *a)
{
	int	size;
	int	i;

	size = ft_lstsize(a);
	i = 0;
	while (a != NULL)
	{
		if (a->data == node)
			break ;
		i++;
		a = a->next;
	}
	return (i <= size / 2);
}

void	pushing(t_stack **a, t_stack **b)
{
	push_b(a, b);
	push_b(a, b);
	while (ft_lstsize(*a) > 3)
		from_a_to_b(a, b);
	sort3(a);
	while (ft_lstsize(*b) > 0)
		from_b_to_a(a, b);
	check_min(a);
	free_stack(a);
	free_stack(b);
}
