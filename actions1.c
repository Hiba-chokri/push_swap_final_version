/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:06:35 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 14:21:52 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top)
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **top)
{
	t_stack	*tmp;

	if (!top || !*top)
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	*top = tmp;
	write(1, "sb\n", 3);
}

void	rotate_a(t_stack **top, int p)
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
	if (p == 1)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack **top, int p)
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
	if (p == 1)
		write(1, "rb\n", 3);
}

void	ft_rotate(t_stack **a, t_stack **b)
{
	rotate_b(b, 0);
	rotate_a(a, 0);
	write(1, "rr\n", 3);
}
