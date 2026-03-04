/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:24:37 by codespace         #+#    #+#             */
/*   Updated: 2026/03/04 08:11:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ================= STRUCT ================= */

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

/* ================= PARSING ================= */

void	parse_args(int argc, char **argv, t_node **a);
long	ft_atol_safe(const char *str, int *ok);
int		has_duplicates(t_node *stack);

/* ================= STACK UTILS ================= */

t_node	*new_node(int value);
void	add_back(t_node **stack, t_node *new);
t_node	*last_node(t_node *stack);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);

int		is_sorted(t_node *stack);
int		min_index(t_node *stack);
int		max_index(t_node *stack);
int		min_index_pos(t_node *stack);

/* ================= INDEXING ================= */

void	assign_index(t_node *stack);

/* ================= POSITION ================= */

void	set_positions(t_node *stack);

/* ================= TARGET ================= */

void	set_target_positions(t_node *a, t_node *b);

/* ================= COST ================= */

void	calculate_costs(t_node *a, t_node *b);
void	execute_cheapest(t_node **a, t_node **b);
int	estimated_total_cost(int cost_a, int cost_b);

/* ================= SORT ================= */

void	sort_small(t_node **a, t_node **b);
void	sort_big(t_node **a, t_node **b);

/* ================= OPERATIONS ================= */

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* ================= UTILS ================= */

void	putstr_fd(const char *s, int fd);
int		abs_val(int x);
char	**split(const char *s, char c);

#endif