/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:29:12 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 07:45:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	int_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	find_index_in_sorted(int *sorted, int n, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	assign_index(t_node *stack)
{
	int		n;
	int		*arr;
	t_node	*cur;
	int		i;

	n = stack_size(stack);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return ;
	cur = stack;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->value;
		cur = cur->next;
	}
	int_sort(arr, n);
	cur = stack;
	while (cur)
	{
		cur->index = find_index_in_sorted(arr, n, cur->value);
		cur = cur->next;
	}
	free(arr);
}