/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:33:17 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:47:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = last_node(*s);
	last->next = first;
}

void	ra(t_node **a)
{
	rotate_up(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate_up(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}