/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:58:53 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 15:08:50 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_args(t_stack **a, int argc, char *argv[])
{
	t_stack	*new;
	int		i;
	int		j;
	char	**tab;

	i = 0;
	new = NULL;
	while (++i < argc)
	{
		j = -1;
		tab = ft_split(argv[i], ' ');
		while (tab[++j])
		{
			while (ft_atoi(tab[j]) == 0 && tab[j][0] != '0')
			{
				if (tab[j][0] == '-' || tab[j][0] == '+')
					break ;
				exit(1);
			}
			new = ft_lstnew(ft_atoi(tab[j]));
			ft_lstadd_back(a, new);
		}
		free_str1(tab);
	}
}

int	is_stack_sorted(t_stack *a)
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

int	check_arg(char **argv)
{
	if (!check(argv))
		return (0);
	if (!count_spaces(argv))
		return (0);
	if (!is_not_integer(argv))
		return (0);
	return (1);
}

void	handle_args_and_sort_stacks(int argc, char *argv[], t_stack **a,
		t_stack **b)
{
	if (argc < 2)
		exit(0);
	if (!check_arg(argv))
		free_error(a);
	else
	{
		ft_split_args(a, argc, argv);
		if (!check_double(*a))
			free_error(a);
	}
	if (is_stack_sorted(*a))
		free_stack(a);
	else
	{
		if (ft_lstsize(*a) == 2)
			sort2(a);
		else if (ft_lstsize(*a) == 3)
			sort3(a);
		else
			pushing(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	handle_args_and_sort_stacks(argc, argv, &a, &b);
	return (0);
}
