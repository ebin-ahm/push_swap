/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:35:26 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:55:57 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	signed_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

int	estimated_total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (abs_val(cost_a) > abs_val(cost_b))
			return (abs_val(cost_a));
		return (abs_val(cost_b));
	}
	return (abs_val(cost_a) + abs_val(cost_b));
}

void	calculate_costs(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		b->cost_b = signed_cost(b->pos, size_b);
		b->cost_a = signed_cost(b->target_pos, size_a);
		b = b->next;
	}
}
