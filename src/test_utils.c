/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:53:38 by lgandari          #+#    #+#             */
/*   Updated: 2024/04/26 13:05:50 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack_node *head)
{
	ft_printf("Stack content: ");
	while (head != NULL)
	{
		ft_printf("%d ", head->num);
		head = head->next;
	}
	ft_printf("\n");
}

t_stack_node	*create_node(int num)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push(t_stack_node **head, int num)
{
	t_stack_node	*node;

	node = create_node(num);
	if (*head == NULL)
		*head = node;
	else
	{
		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}
}

void	free_stack(t_stack_node *head)
{
	t_stack_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
