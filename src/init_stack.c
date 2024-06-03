/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:56:15 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/03 16:28:55 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->num = n;
	node->idx = -1;
	node->push_cost = -1;
	node->over_mid = 0;
	node->smallest_cost = 0;
	node->target = NULL;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
	}
}

static int	get_num(const char *num)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	if (*num == '+')
		num++;
	else if (*num == '-')
	{
		sign = -1;
		num++;
	}
	while (*num)
	{
		if (ft_isdigit(*num) == 0)
			return (print_error(), 0);
		res = res * 10 + *num - '0';
		num++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
		return (print_error(), 0);
	return (res);
}

void	init_stack(t_stack_node **a, char **args)
{
	int	n;
	int	i;

	i = 0;
	while (args[i])
	{
		n = get_num(args[i]);
		append_node(a, n);
		i++;
	}
}
