/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:28:28 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:55:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	die_error(t_node **a)
{
	putstr_fd("Error\n", 2);
	free_stack(a);
	exit(1);
}

int	main(int count, char **args)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (count < 2)
		return (0);
	parse_args(count, args, &a);
	if (!a)
		return (0);
	if (has_duplicates(a))
		die_error(&a);
	if (!is_sorted(a))
	{
		assign_index(a);
		if (stack_size(a) <= 5)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	free_stack(&a);
	return (0);
}