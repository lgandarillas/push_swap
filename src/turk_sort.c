/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:39:13 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 18:02:18 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static void	set_stack_b_values(t_stack_node *a, t_stack_node *b)
{
	update_stack_idx(a);
	update_stack_idx(b);
	set_target_b(a, b);
}

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

static void	turk_pa(t_stack_node **a, t_stack_node **b)
{
	ensure_cheapest_up(a, (*b)->target, 'a');
	pa(a, b);
}

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
