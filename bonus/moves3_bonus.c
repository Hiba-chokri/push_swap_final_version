/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:56:03 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 15:29:04 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_reverse_rotate_bonus(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*before_lst;

	if (!*top || !*top || !((*top)->next))
		return ;
	tmp = ft_lstlast(*top);
	tmp->next = *top;
	*top = tmp;
	before_lst = *top;
	while (before_lst->next != tmp)
		before_lst = before_lst->next;
	before_lst->next = NULL;
}

void	rra_bonus(t_stack **top)
{
	ft_reverse_rotate_bonus(top);
}

void	rrb_bonus(t_stack **top)
{
	ft_reverse_rotate_bonus(top);
}

void	push_a_bonus(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
}

void	push_b_bonus(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}
