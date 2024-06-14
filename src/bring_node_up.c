/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_node_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:00:51 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 18:05:01 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	bring_cheapest_up(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b);
	update_stack_idx(*a);
	update_stack_idx(*b);
}

void	reverse_bring_cheapest_up(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b);
	update_stack_idx(*a);
	update_stack_idx(*b);
}

void	ensure_cheapest_up(t_stack_node **stack,
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

void	bring_min_up(t_stack_node **a)
{
	while ((*a)->num != get_min_node(*a)->num)
	{
		if (get_min_node(*a)->over_mid)
			ra(a);
		else
			rra(a);
	}
}
