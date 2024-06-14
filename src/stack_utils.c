/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:30:56 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 16:55:43 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	has_duplicates(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->num == checker->num)
				return (1);
			checker = checker ->next;
		}
		current = current->next;
	}
	return (0);
}

void	print_stack(t_stack_node *stack)
{
	t_stack_node	*current;

	current = stack;
	while (current != NULL)
	{
		ft_printf("Node='%d'\n", current->num);
		current = current->next;
	}
}

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*current;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}

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
