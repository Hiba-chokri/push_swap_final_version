/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:11:51 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 02:16:52 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	count_spaces1(char *argv[])
{
	int	size;
	int	i;
	int	count;
	int	j;

	j = 0;
	count = 0;
	i = 1;
	while (argv[i])
	{
		size = ft_strlen_gnl(argv[i]);
		while (argv[i][j] == ' ')
		{
			count++;
			j++;
		}
		if (size == count)
			return (0);
		i++;
	}
	return (1);
}

int	is_not_integer1(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isalpha(argv[i][j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check1(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& (!ft_isdigit(argv[i][j + 1])))
				return (0);
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& (ft_isdigit(argv[i][j - 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double1(t_stack *a)
{
	t_stack *tmp;

	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->data == tmp->data)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}
