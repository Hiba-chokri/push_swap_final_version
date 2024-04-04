/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:59:23 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 14:06:46 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	handling_errors(char *line, t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free_stack1(a);
	free_stack1(b);
	free(line);
	exit(1);
}
void	ft_split_args2(t_stack **a, int argc, char *argv[])
{
	t_stack	*new;
	int		i;
	int		j;
	char	**tab;

	i = 1;
	new = NULL;
	while (i < argc)
	{
		j = 0;
		tab = ft_split(argv[i], ' ');
		while (tab[j])
		{
			while (ft_atoi(tab[j]) == 0 && tab[j][0] != '0')
			{
				if (tab[j][0] == '-' || tab[j][0] == '+')
					break ;
				exit(1);
			}
			new = ft_lstnew(ft_atoi(tab[j]));
			ft_lstadd_back(a, new);
			j++;
		}
		free_str2(tab);
		i++;
	}
}

int	check_arg1(char **argv)
{
	if (!check1(argv))
		return (0);
	if (!count_spaces1(argv))
		return (0);
	if (!is_not_integer1(argv))
		return (0);
	return (1);
}

void	execute_command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_a_bonus(a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_b_bonus(b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_a_bonus(a, b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_b_bonus(a, b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate_a_bonus(a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate_b_bonus(b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		ft_rotate_bonus(a, b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		ft_reverse_rotate_bonus(a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		ft_reverse_rotate_bonus(b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr_bonus(a, b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ft_ss_bonus(a, b);
	else
		handling_errors(line, a, b);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_command(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_stack_sorted1(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
    free_stack1(a);
    free_stack1(b);
	system("leaks checker");
}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        exit(0);
    a = NULL;
    b = NULL;
    if (!check_arg1(argv))
        free_error1(&a);
    else
    {
        ft_split_args2(&a, argc, argv);
		if (!check_double1(a))
			free_error1(&a);
		else
    		checker(&a,&b);
	}
	return (0);
}