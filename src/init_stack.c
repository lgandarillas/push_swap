/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:56:15 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/01 12:48:02 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_num(const char *num)
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
		{
			print_error();
			return (0);
		}
		res = res * 10 + *num - '0';
		num++;
	}
	res *= sign;
	if (res > INT_MAX || res < INT_MIN)
	{
		print_error();
		return (0);
	}
	return (res);
}

/*
void	init_stack_a(t_stack_node **a, char **args)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}
*/
