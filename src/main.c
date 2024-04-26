/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:50:28 by lgandari          #+#    #+#             */
/*   Updated: 2024/04/26 13:00:06 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Create parser

/*
int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (argc == 2 && !argv[1][0])
		return (1);
	else if (argc == 2)
		ft_printf("Hola\n");
	return (0);
}
*/

// TESTING COMMANDS
int	main(void)
{
	t_stack_node	*head;

	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	print_stack(head);
	free_stack(head);
	return (0);
}
