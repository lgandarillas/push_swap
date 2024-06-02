/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:57:57 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/02 18:10:59 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;
	t_stack_node	*penultimate;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = get_last_node(*head);
	penultimate = (*head);
	while (penultimate->next != last_node)
		penultimate = penultimate->next;
	penultimate->next = NULL;
	last_node->next = (*head);
	(*head) = last_node;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
