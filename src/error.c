/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 10:57:13 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 15:56:43 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	current = stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	free_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	print_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	stack_error(t_stack_node *a, char **args)
{
	free_stack(a);
	free_split(args);
	print_error();
}
