/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:39:13 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/04 20:58:33 by lgandari         ###   ########.fr       */
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

// OK (nuevo)
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

// OK, (nuevo)
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
		a = a->next;
	}
}

// OK, pero TESTEAR
static void	update_stack_push_cost(t_stack_node *a, t_stack_node *b)
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
static void	update_stack_smallest_cost(t_stack_node *stack)
{
	long			smallest_cost;
	t_stack_node	*cheapest;

	if (!stack)
		return ;
	smallest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < smallest_cost)
		{
			smallest_cost = stack->push_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->smallest_cost = 1;
}

// OK (nuevo)
static void	update_stack_a(t_stack_node *a, t_stack_node *b)
{
	update_stack_idx(a);
	update_stack_idx(b);
	update_stack_targets(a, b);
	update_stack_push_cost(a, b);
	update_stack_smallest_cost(a);
}

// OK, pero TESTEAR
static t_stack_node	*get_smallest_cost_node(t_stack_node **a)
{
	t_stack_node	*current;

	if (a == NULL || *a == NULL)
		return (NULL);
	current = *a;
	while (current)
	{
		if (current->smallest_cost == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}

// OK, pero TESTEAR
static void	bring_cheapest_up(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	update_stack_idx(*a);
	update_stack_idx(*b);
}

// OK, pero TESTEAR
static void	reverse_bring_cheapest_up(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	update_stack_idx(*a);
	update_stack_idx(*b);
}

// OK, pero TESTEAR
static void	ensure_cheapest_up(t_stack_node **stack,
	t_stack_node *cheapest, char s_name)
{
	while (*stack != cheapest)
	{
		if (s_name == 'a')
		{
			if (cheapest->over_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (s_name == 'b')
		{
			if (cheapest->over_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

// OK, pero TESTEAR
static void	turk_pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_smallest_cost_node(a);
	if (cheapest->over_mid && cheapest->target->over_mid)
		bring_cheapest_up(a, b, cheapest);
	else if (!(cheapest->over_mid) && !(cheapest->target->over_mid))
		reverse_bring_cheapest_up(a, b, cheapest);
	ensure_cheapest_up(a, cheapest, 'a');
	ensure_cheapest_up(b, cheapest->target, 'b');
	pb(a, b);
}

// OK, pero TESTEAR
static t_stack_node	*get_min_node(t_stack_node *s)
{
	t_stack_node	*current;
	t_stack_node	*smallest;

	if (s == NULL)
		return (NULL);
	smallest = s;
	current = s->next;
	while (current)
	{
		if (current->num < smallest->num)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

// OK, pero TESTEAR
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match_idx;

	while (b)
	{
		best_match_idx = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < best_match_idx)
			{
				best_match_idx = current_a->num;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_idx == LONG_MAX)
			b->target = get_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

// OK, pero TESTEAR
static void	set_stack_b_values(t_stack_node *a, t_stack_node *b)
{
	update_stack_idx(a);
	update_stack_idx(b);
	set_target_b(a, b);
}

// OK, pero TESTEAR
static void	turk_pa(t_stack_node **a, t_stack_node **b)
{
	ensure_cheapest_up(a, (*b)->target, 'a');
	pa(a, b);
}

// OK, pero TESTEAR
static void	bring_min_up(t_stack_node **a)
{
	while ((*a)->num != get_min_node(*a)->num)
	{
		if (get_min_node(*a)->over_mid)
			ra(a);
		else
			rra(a);
	}
}

// REVISAR -> anadir a .h
void	turk_sort(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(a, b);
	len_b = stack_len(*b);
	if (len_b == 2 && (*b)->num < (*b)->next->num)
		sb(b);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		update_stack_a(*a, *b);
		turk_pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_stack_b_values(*a, *b);
		turk_pa(a, b);
	}
	update_stack_idx(*a);
	bring_min_up(a);
}
