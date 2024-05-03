/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:50:28 by lgandari          #+#    #+#             */
/*   Updated: 2024/05/03 21:16:07 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*parse_cmds(int argc, char **argv)
{
	int		i;
	char	*new;
	char	*result;

	i = 2;
	result = ft_strdup(argv[1]);
	if (!result)
		return (NULL);
	if (argc > 2)
	{
		while (i < argc)
		{
			new = ft_strjoin(result, argv[i]);
			free(result);
			result = ft_strdup(new);
			if (!result)
				return (NULL);
			free(new);
			i++;
		}
	}
	return (result);
}

int	main(int argc, char **argv)
{
	char	**cmds;

	if (argc == 1)
		return (1);
	else if (argc == 2 && !argv[1][0])
		return (1);
	else
	{
		argv[1] = parse_cmds(argc, argv);
		cmds = ft_split(argv[1], ' ');
	}
	print_split(cmds);
	free_split(cmds);
	free(argv[1]);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	//if (argc == 1 || (argc == 2 && !argv[1][0]))
	//	return (1);
	//else if (argc == 2)
	//	argv = ft_split(argv[1], ' ');
	//init_stack_a(&a, argv + 1);

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
	return (0);
}
*/
