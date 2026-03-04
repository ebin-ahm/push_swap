/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:35:19 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:46:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_cheapest(t_node *b)
{
	t_node	*best;
	int		best_cost;
	int		c;

	best = b;
	best_cost = INT_MAX;
	while (b)
	{
		c = estimated_total_cost(b->cost_a, b->cost_b);
		if (c < best_cost)
		{
			best_cost = c;
			best = b;
		}
		b = b->next;
	}
	return (best);
}

static void	do_rot_a(t_node **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	do_rot_b(t_node **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

static void	do_both(t_node **a, t_node **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		(*ca)--;
		(*cb)--;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		(*ca)++;
		(*cb)++;
	}
}

void	execute_cheapest(t_node **a, t_node **b)
{
	t_node	*best;
	int		ca;
	int		cb;

	best = find_cheapest(*b);
	ca = best->cost_a;
	cb = best->cost_b;
	do_both(a, b, &ca, &cb);
	do_rot_a(a, &ca);
	do_rot_b(b, &cb);
	pa(a, b);
}