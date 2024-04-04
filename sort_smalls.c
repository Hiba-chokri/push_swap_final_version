/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smalls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:23:18 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/03 16:37:38 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **top)
{
	if (ft_lstsize(*top) > 2 && ((*top)->data > (*top)->next->data)
		&& ((*top)->data < (*top)->next->next->data))
	{
		if ((*top)->next->data < (*top)->next->next->data)
			swap_a(top);
	}
	else if (((*top)->data > (*top)->next->data)
		&& ((*top)->data > (*top)->next->next->data))
	{
		if ((*top)->next->data > (*top)->next->next->data)
		{
			swap_a(top);
			rra(top);
		}
		else
			rotate_a(top, 1);
	}
	else if (((*top)->data < (*top)->next->data)
		&& ((*top)->data < (*top)->next->next->data))
	{
		if ((*top)->next->data > (*top)->next->next->data)
		{
			swap_a(top);
			rotate_a(top, 1);
		}
	}
	else if (((*top)->data < (*top)->next->data)
		&& ((*top)->data > (*top)->next->next->data))
		rra(top);
}

void	sort2(t_stack **top)
{
	if ((*top)->data > (*top)->next->data)
		swap_a(top);
}
