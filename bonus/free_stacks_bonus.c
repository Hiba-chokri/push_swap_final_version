/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:15:24 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 01:21:53 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	free_stack1(t_stack **x)
{
	t_stack	*tmp;

	while (*x != NULL)
	{
		tmp = *x;
		*x = (*x)->next;
		free(tmp);
	}
	return (0);
}

void	ft_error1(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	free_error1(t_stack **a)
{
	ft_error1();
	free_stack1(a);
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
