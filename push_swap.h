/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichokri <hichokri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:50:33 by hichokri          #+#    #+#             */
/*   Updated: 2024/04/04 13:05:59 by hichokri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_stack 
{
	int data;
	struct s_stack *next;
} t_stack;
void	sort2(t_stack **top);
void	sort3(t_stack **top);
void	swap_a(t_stack **top);
void	swap_b(t_stack **top);
void	rotate_a(t_stack **top, int p);
void	rotate_b(t_stack **top, int p);
void	ft_rotate(t_stack **a, t_stack **b);
void	rrb(t_stack **top);
void	ft_reverse_rotate(t_stack **top);
void	rra(t_stack **top);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
int		find_min(t_stack *a);
int		ft_max(int x, int y);
int		find_index(t_stack *x, int nb);
int		calculate_cost(t_stack *a, t_stack *b, int node, int target);
long	find_target(int node, t_stack *b);
long	find_bigger_targ(t_stack *b);
int		find_min_cost(t_stack *a, int size);
int		find_min_cost_index(t_stack *a, int size);
int		count_spaces(char *argv[]);
int		count_spaces(char *argv[]);
int	ft_isdigit(int c);
void	from_a_to_b(t_stack **a, t_stack **b);
void	from_b_to_a(t_stack **a, t_stack **b);
int		is_not_integer(char *argv[]);
int		greater_than_int(char *argv[]);
int		check_double(t_stack *a);
int	ft_isalpha(int c);
t_stack	*ft_lstlast (t_stack *lst);
int		check_arg(char **argv);
t_stack	*ft_lstnew(int content);
int	ft_lstsize(t_stack *lst);
size_t	ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		check_node_pos(int node, t_stack *a);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		check_target_pos(int target, t_stack *b);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		check(char *argv[]);
long	ft_atoi(char *nptr);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int	ft_isalpha(int c);
void	sort4(t_stack **a, t_stack **b);
int		find_max(t_stack **x);
long	find_target_a(int node, t_stack *a);
int		calculate_cost1(t_stack *a, t_stack *b, int node, int target);
void	ft_error(void);
void	calculate_best_target_b_to_a(t_stack **a, t_stack **b,
			long *best_target, int *node);
void	check_min(t_stack **a);
int		free_stack(t_stack **a);
size_t	ft_strlen(const char *s);
char	*ft_strchr_gnl(char *s, int c);
void	free_error(t_stack **a);
void	free_exit(t_stack **a);
char	*ft_strdup(const char *s);
#endif
