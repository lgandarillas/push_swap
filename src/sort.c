/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:39:13 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/03 10:39:00 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = get_max_node(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}

int	is_sorted(t_stack_node *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}

// OK, pero REVISAR
static void	update_stack_values(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->idx = i;
		if (i <= median)
			stack->over_mid = 1;
		else
			stack->over_mid = 0;
		stack = stack->next;
		i++;
	}
}

// REVISAR
static void	set_node_a_values(t_stack_node *a, t_stack_node *b)
{
	update_stack_values(a);
	update_stack_values(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

// REVISAR -> anadir a .h
void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	i;

	len_a = stack_len(*a);
	i = 0;
	while (len_a-- > 3 && !is_sorted(*a) && i++ < 2)
		pb(a, b); // SIN HACER + anadir a .h
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b); 	// SIN HACER + anadir a .h
		move_a_to_b(a, b);		// SIN HACER + anadir a .h
	}
}
