/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:30:56 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 17:08:52 by lgandari         ###   ########.fr       */
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

int	is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}
