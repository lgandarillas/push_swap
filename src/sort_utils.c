/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:40:58 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 17:45:13 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	update_stack_idx(t_stack_node *stack)
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

void	update_stack_a(t_stack_node *a, t_stack_node *b)
{
	update_stack_idx(a);
	update_stack_idx(b);
	update_stack_targets(a, b);
	update_stack_push_cost(a, b);
	update_stack_smallest_cost(a);
}
