/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:15:24 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 15:22:10 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_stack1(t_stack **x)
{
	t_stack	*tmp;

	while (*x != NULL)
	{
		tmp = *x;
		*x = (*x)->next;
		free(tmp);
	}
}

void	ft_error1(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_error1(t_stack **a)
{
	free_stack1(a);
	ft_error1();
}

void	free_exit1(t_stack **a)
{
	free_stack1(a);
	exit(0);
}

int	is_stack_sorted1(t_stack *a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->data > tmp->data)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}
