/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:31:05 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/03 07:27:29 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *a)
{
	t_stack	*tmp;
	int		min;

	tmp = a;
	min = tmp->data;
	while (tmp != NULL)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max(t_stack **x)
{
	t_stack	*tmp;
	int		max;

	tmp = *x;
	max = tmp->data;
	while (tmp != NULL)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	find_index(t_stack *x, int nb)
{
	int	index;

	index = 0;
	while (x != NULL)
	{
		if (x->data == nb)
			return (index);
		index++;
		x = x->next;
	}
	return (-1);
}

int	ft_max(int x, int y)
{
	int	max;

	max = 0;
	if (x > y)
		max = x;
	else
		max = y;
	return (max);
}

void	check_min(t_stack **a)
{
	int	min;
	int	check_pos;

	min = find_min(*a);
	check_pos = check_node_pos(min, *a);
	if (check_pos == 1)
	{
		while (min != (*a)->data)
			rotate_a(a, 1);
	}
	else
	{
		while (min != (*a)->data)
			rra(a);
	}
}
