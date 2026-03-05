/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:37 by codespace         #+#    #+#             */
/*   Updated: 2026/03/05 07:08:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->pos = 0;
	n->target_pos = 0;
	n->cost_a = 0;
	n->cost_b = 0;
	n->next = NULL;
	return (n);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_back(t_node **stack, t_node *newn)
{
	t_node	*last;

	if (!stack || !newn)
		return ;
	if (!*stack)
	{
		*stack = newn;
		return ;
	}
	last = last_node(*stack);
	last->next = newn;
}

int	stack_size(t_node *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}