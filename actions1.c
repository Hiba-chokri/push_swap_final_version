/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:06:35 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 04:48:13 by hichokri         ###   ########.fr       */
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


// void swap_a(t_stack **top)
// {
//      t_stack *tmp;

//     if (!top || !*top)
//         return ;
//     tmp = (*top)->next;
//     (*top)->next = (*top)->next->next;
//     tmp->next= *top;
//     *top = tmp;
//     write(1, "sa\n", 3);
// }
// void swap_b(t_stack **top)
// {
//      t_stack *tmp;

//     if (!top || !*top)
//         return ;
//     tmp = (*top)->next;
//     (*top)->next = (*top)->next->next;
//     tmp->next= *top;
//     *top = tmp;
//     write(1, "sb\n", 3);
// }
// // rotate
// void rotate_a(t_stack **top)
// {
//     t_stack *tmp;
//     // t_stack *ptr;

//     if (!top || !*top || !((*top)->next))
//         return ;
//     // ptr = *top;
//     tmp = *top;
//     while (tmp->next != NULL)
//         tmp = tmp->next;
//     tmp->next = *top;
//     *top = (*top)->next;
//     tmp->next->next = NULL;
//     write(1, "ra\n", 3);
// }
// void rotate_b(t_stack **top)
// {
//      t_stack *tmp;
//     // t_stack *ptr;

//     if (!top || !*top || !((*top)->next))
//         return ;
//     // ptr = *top;
//     tmp = *top;
//     while (tmp->next != NULL)
//         tmp = tmp->next;
//     tmp->next = *top;
//     *top = (*top)->next;
//     tmp->next->next = NULL;
//     write(1, "rb\n", 3);
  
// }
// void ft_rotate(t_stack **a, t_stack **b)
// {
//     // printf("test\n");
//     rotate_b(b);
//     rotate_a(a);
// }
// void ft_reverse_rotate(t_stack **top)
// {
//     t_stack *tmp;
//     t_stack *before_lst;

//     if (!*top || !*top || !((*top)->next))
//         return ;
//     tmp = ft_lstlast(*top);
//     tmp->next = *top;
//     *top = tmp;
//     before_lst = *top;
//     while (before_lst->next != tmp)
//         before_lst = before_lst->next;
//     before_lst->next = NULL;
// }

// void rra(t_stack **top)
// {
//     ft_reverse_rotate(top);