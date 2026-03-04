/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:29:21 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 08:05:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol_safe(const char *str, int *ok)
{
	long	sign;
	long	res;

	*ok = 1;
	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (*ok = 0, 0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (*ok = 0, 0);
		res = res * 10 + (*str - '0');
		if (sign == 1 && res > INT_MAX)
			return (*ok = 0, 0);
		if (sign == -1 && (-res) < INT_MIN)
			return (*ok = 0, 0);
		str++;
	}
	return (res * sign);
}

int	has_duplicates(t_node *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static void	die_error(t_node **a)
{
	putstr_fd("Error\n", 2);
	free_stack(a);
	exit(1);
}

static void	add_value(t_node **a, long v, int ok)
{
	t_node	*n;

	if (!ok)
		die_error(a);
	n = new_node((int)v);
	if (!n)
		die_error(a);
	add_back(a, n);
}

static void	parse_split(char *arg, t_node **a)
{
	char	**parts;
	int		i;
	int		ok;
	long	v;

	parts = split(arg, ' ');
	if (!parts)
		die_error(a);
	i = 0;
	while (parts[i])
	{
		v = ft_atol_safe(parts[i], &ok);
		add_value(a, v, ok);
		i++;
	}
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
}

void	parse_args(int count, char **args, t_node **a)
{
	int		i;
	int		ok;
	long	v;

	if (count == 2)
		return (parse_split(args[1], a));
	i = 1;
	while (i < count)
	{
		v = ft_atol_safe(args[i], &ok);
		add_value(a, v, ok);
		i++;
	}
}