/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:51:55 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/03 23:35:45 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a_bonus(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top)
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
}

void	swap_b_bonus(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top)
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
}

void	rotate_a_bonus(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top || !((*top)->next))
		return ;
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *top;
	*top = (*top)->next;
	tmp->next->next = NULL;
}

void	rotate_b_bonus(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top || !((*top)->next))
		return ;
	tmp = *top;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *top;
	*top = (*top)->next;
	tmp->next->next = NULL;
}

void	ft_rotate_bonus(t_stack **a, t_stack **b)
{
	rotate_b_bonus(b);
	rotate_a_bonus(a);
}
