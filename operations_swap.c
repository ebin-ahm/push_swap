/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:33:25 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:47:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **s)
{
	t_node	*first;
	t_node	*second;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_node **a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
}