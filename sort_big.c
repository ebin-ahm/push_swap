/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:34:45 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 10:42:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int n)
{
	return ((n * 91) / 100);
}

/* Sort exactly 3 elements in A (by index). DOES NOT touch B. */
static void	sort_3_only(t_node **a)
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

static void	push_chunks_to_b(t_node **a, t_node **b)
{
	int	n;
	int	chunk;
	int	limit;
	int	pushed;

	n = stack_size(*a);
	chunk = chunk_size(n);
	limit = chunk;
	pushed = 0;
	while (stack_size(*a) > 3)
	{
		if ((*a)->index < limit)
		{
			pb(a, b);
			pushed++;
			if ((*b)->index < (limit - (chunk / 2)))
				rb(b);
			if (pushed == limit)
				limit += chunk;
			if (limit > n)
				limit = n;
		}
		else
			ra(a);
	}
}

static void	final_rotate_min_to_top(t_node **a)
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
}

void	sort_big(t_node **a, t_node **b)
{
	push_chunks_to_b(a, b);

	/* Sort remaining 3 in A only */
	if (!is_sorted(*a))
		sort_3_only(a);

	/* Greedy reinsertion */
	while (*b)
	{
		set_positions(*a);
		set_positions(*b);
		set_target_positions(*a, *b);
		calculate_costs(*a, *b);
		execute_cheapest(a, b);
	}

	final_rotate_min_to_top(a);
}