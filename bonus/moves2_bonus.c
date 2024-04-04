/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 07:54:48 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 15:26:29 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rrr_bonus(t_stack **a, t_stack **b)
{
	ft_reverse_rotate_bonus(a);
	ft_reverse_rotate_bonus(b);
}

void	ft_ss_bonus(t_stack **a, t_stack **b)
{
	swap_a_bonus(a);
	swap_b_bonus(b);
}

void	free_str2(char **tab)
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
