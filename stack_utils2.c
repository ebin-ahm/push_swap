/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:28 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:44:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	min_index(t_node *stack)
{
	int	m;

	m = INT_MAX;
	while (stack)
	{
		if (stack->index < m)
			m = stack->index;
		stack = stack->next;
	}
	return (m);
}

int	max_index(t_node *stack)
{
	int	m;

	m = INT_MIN;
	while (stack)
	{
		if (stack->index > m)
			m = stack->index;
		stack = stack->next;
	}
	return (m);
}

int	min_index_pos(t_node *stack)
{
	int	min_i;
	int	min_p;

	min_i = INT_MAX;
	min_p = 0;
	while (stack)
	{
		if (stack->index < min_i)
		{
			min_i = stack->index;
			min_p = stack->pos;
		}
		stack = stack->next;
	}
	return (min_p);
}