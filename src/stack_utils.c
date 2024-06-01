/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:30:56 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/01 16:35:49 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack_node *s)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = s;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	print_stack(t_stack_node *s)
{
	t_stack_node	*current;

	current = s;
	while (current != NULL)
	{
		ft_printf("Node='%d'\n", current->num);
		current = current->next;
	}
}

int	stack_len(t_stack_node *s)
{
	int				len;
	t_stack_node	*current;

	current = s;
	len = 0;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}
