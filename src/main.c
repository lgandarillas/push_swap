/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:50:28 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/01 12:54:02 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	char	**cmds;
	//t_stack_node	*a;
	//t_stack_node	*b;

	//a = NULL;
	//b = NULL;
	cmds = parser(argc, argv);
	print_split(cmds);

	// TO DO
	//init_stack_a(&a, ...);
	/*
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	*/
	free_split(cmds);
	return (0);
}
