/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:11:46 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/02 18:39:26 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pb\n");
}
