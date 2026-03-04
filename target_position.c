/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:36:45 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:45:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_of_index(t_node *a, int idx)
{
	while (a)
	{
		if (a->index == idx)
			return (a->pos);
		a = a->next;
	}
	return (0);
}

void	set_target_positions(t_node *a, t_node *b)
{
	t_node	*cur_a;
	t_node	*cur_b;
	int		best_idx;

	while (b)
	{
		best_idx = INT_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->index > b->index && cur_a->index < best_idx)
				best_idx = cur_a->index;
			cur_a = cur_a->next;
		}
		if (best_idx == INT_MAX)
			b->target_pos = pos_of_index(a, min_index(a));
		else
			b->target_pos = pos_of_index(a, best_idx);
		cur_b = b;
		b = b->next;
		(void)cur_b;
	}
}