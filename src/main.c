/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:50:28 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/02 16:58:05 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	char			**args;
	t_stack_node	*a;
	//t_stack_node	*b;

	a = NULL;
	//b = NULL;
	args = parser(argc, argv);
	//print_split(args);
	init_stack(&a, args);
	print_stack(a);
	ft_printf("Is sorted = %d\n", is_sorted(a));
	ft_printf("Has duplicates = %d\n", has_duplicates(a));
	if (has_duplicates(a))
		stack_error(a, args);
	sa(&a);
	print_stack(a);
	/*
	if (!is_sorted(a) && !has_duplicates(a))
	{
		if (stack_len(a) == 2) -> OK
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	*/
	free_stack(a);
	free_split(args);
	return (0);
}
