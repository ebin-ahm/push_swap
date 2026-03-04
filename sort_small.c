/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:34:49 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:47:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_node **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static void	sort_3(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->index;
	y = (*a)->next->index;
	z = (*a)->next->next->index;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	push_min_to_b(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	set_positions(*a);
	pos = min_index_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < size)
			rra(a);
	pb(a, b);
}

void	sort_small(t_node **a, t_node **b)
{
	int	n;

	n = stack_size(*a);
	if (n <= 1)
		return ;
	if (n == 2)
		return (sort_2(a));
	if (n == 3)
		return (sort_3(a));
	while (stack_size(*a) > 3)
		push_min_to_b(a, b);
	sort_3(a);
	while (*b)
		pa(a, b);
}