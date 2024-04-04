/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:38:01 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 13:25:35 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// long	find_target_a(int node, t_stack *a)
// {
// 	long	closest_target;
// 	t_stack	*current;

// 	closest_target = LONG_MAX;
// 	current = a;
// 	while (current != NULL)
// 	{
// 		if (node < current->data && current->data < closest_target)
// 			closest_target = current->data;
// 		current = current->next;
// 	}
// 	if (closest_target == LONG_MAX)
// 		closest_target = find_min(a);
// 	return (closest_target);
// }

// void	calculate_best_target_b_to_a(t_stack **a, t_stack **b,
// 		long *best_target, int *node)
// {
// 	t_stack	*current;

// 	current = *b;
// 	*best_target = find_target_a(current->data, *a);
// 	*node = current->data;
// }

// void	rotate_to_best_target_b_to_a(t_stack **a, t_stack **b, int best_target,
// 		int node)
// {
// 	int	above_target;
// 	int	above_node;

// 	above_target = check_target_pos(best_target, *a);
// 	above_node = check_node_pos(node, *b);
// 	if (above_target == 1 && above_node == 1)
// 	{
// 		while (best_target != (*a)->data && node != (*b)->data)
// 			ft_rotate(a, b);
// 	}
// 	else if (above_target == 0 && above_node == 0)
// 	{
// 		while (best_target != (*a)->data && node != (*b)->data)
// 			rrr(a, b);
// 	}
// }

// void	adjust_stacks_b_to_a(t_stack **a, t_stack **b, int best_target,
// 		int node)
// {
// 	int	above_target;
// 	int	above_node;

// 	above_target = check_target_pos(best_target, *a);
// 	above_node = check_node_pos(node, *b);
// 	if (above_target == 1)
// 	{
// 		while (best_target != (*a)->data)
// 			rotate_a(a, 1);
// 	}
// 	else
// 	{
// 		while (best_target != (*a)->data)
// 			rra(a);
// 	}
// }

// void	from_b_to_a(t_stack **a, t_stack **b)
// {
// 	long	best_target;
// 	int		node;

// 	node = 0;
// 	best_target = 0;
// 	best_target = find_target_a((*b)->data, *a);
// 	node = (*b)->data;
// 	adjust_stacks_b_to_a(a, b, best_target, node);
// 	push_a(a, b);
// }



long find_target_a(int node, t_stack *a)
{
    long closest_target ;
    t_stack *current;

    closest_target = LONG_MAX;
    current = a;
    while (current != NULL)
    {
        if (node < current->data && current->data < closest_target)
            closest_target = current->data;
        current = current->next;
    }
    return (closest_target);
}
void calculate_best_target_b_to_a(t_stack **a, t_stack **b, long *best_target, int *node)
{
    t_stack *current = *b;

        *best_target = find_target_a(current->data, *a);
        if (*best_target == LONG_MAX)
           *best_target = find_min(*a);
}

void rotate_to_best_target_b_to_a(t_stack **a, t_stack **b, int best_target, int node)
{
    int above_target ;
    int above_node ;

above_target = check_target_pos(best_target, *a);
above_node = check_node_pos(node, *b);
    if (above_target == 1 && above_node == 1)
    {
        while (best_target != (*a)->data && node != (*b)->data)
            ft_rotate(a,b);
    }
    else if (above_target == 0 && above_node == 0)
    {
        while (best_target != (*a)->data && node != (*b)->data)
            rrr(a, b);
    }
}

void adjust_stacks_b_to_a(t_stack **a, t_stack **b, int best_target, int node)
{
    int above_target ;
    int above_node ;

above_target = check_target_pos(best_target, *a);
above_node = check_node_pos(node, *b);
    if (above_target == 1)
    {
        while (best_target != (*a)->data)
            rotate_a(a,1);
    }
    else
    {
        while (best_target != (*a)->data)
            rra(a);
    }
    if (above_node == 1)
        while (node != (*b)->data)
            rotate_b(b,1);
    else
    {
        while(node != (*b)->data)
            rrb(b);
    }
}

void from_b_to_a(t_stack **a, t_stack **b)
{
    long best_target = LONG_MAX;
    int node = (*b)->data;

    calculate_best_target_b_to_a(a, b, &best_target, &node);
    rotate_to_best_target_b_to_a(a, b, best_target, node);
    adjust_stacks_b_to_a(a, b, best_target, node);
    push_a(a, b);
}