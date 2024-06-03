/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:39:13 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/03 11:37:33 by lgandari         ###   ########.fr       */
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

// OK, pero TESTEAR
static void	update_stack_idx(t_stack_node *stack)
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

// OK, pero TESTEAR
static void	update_stack_targets(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*b_node;
	t_stack_node	*target;
	long			closest_smaller;

	while (a)
	{
		closest_smaller = LONG_MIN;
		b_node = b;
		while (b_node)
		{
			if (b_node->num < a->num && b_node->num > closest_smaller)
			{
				closest_smaller = b_node->num;
				target = b_node;
			}
			b_node = b_node->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target = get_max_node(b);
		else
			a->target = target;
	}
}

// OK, pero TESTEAR
static void	update_stack_push_cost(a, b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->idx;
		if (!(a->over_mid))
			a->push_cost = len_a - (a->idx);
		if (a->target->over_mid)
			a->push_cost += a->target->idx;
		else
			a->push_cost += len_b - (a->target->idx);
		a = a->next;
	}
}

// OK, pero TESTEAR
static void update_stack_smallest_cost(t_stack_node *stack)
{
	long			smallest_cost;
	t_stack_node	*best_node;

	if (!stack)
		return ;
	smallest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < smallest_cost)
		{
			smallest_cost = stack->push_cost;
			best_node = stack;
		}
		stack = stack->next;
	}
	best_node->smallest_cost = 1;
}

// REVISAR
static void	set_stack_values(t_stack_node *a, t_stack_node *b)
{
	update_stack_idx(a);
	update_stack_idx(b);
	update_stack_targets(a, b);
	update_stack_push_cost(a, b);
	update_stack_smallest_cost(a);
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
		set_stack_values(*a, *b);
		move_a_to_b(a, b);		// SIN HACER + anadir a .h
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);	// SIN HACER + anadir a .h
		move_b_to_a(a, b);		// SIN HACER + anadir a .h
	}
	current_index(*a);			// SIN HACER + anadir a .h
	min_on_top(a);				// SIN HACER + anadir a .h
}
