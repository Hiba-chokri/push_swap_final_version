/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 06:35:17 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 15:01:16 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_stack(t_stack **x)
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

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_error(t_stack **a)
{
	free_stack(a);
	ft_error();
}

void	free_exit(t_stack **a)
{
	free_stack(a);
}

void	free_str1(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
