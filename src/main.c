/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:50:28 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/03 18:59:02 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	char			**args;
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	args = parser(argc, argv);
	init_stack(&a, args);
	print_stack(a);
	if (has_duplicates(a))
		stack_error(a, args);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			turk_sort(&a, &b);
	}
	print_stack(a);
	free_stack(a);
	free_split(args);
	return (0);
}
