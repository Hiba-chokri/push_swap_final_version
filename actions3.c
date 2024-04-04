/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:26:49 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 05:03:55 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(t_stack **top)
{
    t_stack *tmp;
    t_stack *before_lst;

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

void rra(t_stack **top)
{
    ft_reverse_rotate(top);
    write(1, "rra\n",4);
}
void rrb(t_stack **top)
{
    ft_reverse_rotate(top);
    write(1, "rrb\n",4);
}

void	push_a(t_stack **a, t_stack **b)
{
	  t_stack *tmp;


    if(*b != NULL)
    {
        tmp = *b;
        *b = (*b)->next;
        tmp->next = *a;
        *a = tmp;
    }
    write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	 t_stack *tmp;

    if (*a != NULL)
    {
        tmp = *a;
        *a = (*a)->next;
        tmp->next = *b;
        *b = tmp;
    }
    write(1, "pb\n", 3);
}
