/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:06:41 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 17:07:33 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack_node	*get_max_node(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*biggest;

	if (stack == NULL)
		return (NULL);
	biggest = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (current->num > biggest->num)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}
