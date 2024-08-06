/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:42:09 by lgandari          #+#    #+#             */
/*   Updated: 2024/08/06 20:07:33 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static char	*get_cmd_line(int argc, char **argv)
{
	int		i;
	char	*linecmds;
	char	*newcmd;
	char	*aux;

	i = 2;
	linecmds = ft_strjoin(argv[1], " ");
	while (i < argc)
	{
		newcmd = ft_strjoin(argv[i], " ");
		aux = ft_strjoin(linecmds, newcmd);
		free(newcmd);
		free(linecmds);
		linecmds = aux;
		i++;
	}
	return (linecmds);
}

char	**parser(int argc, char **argv)
{
	char	**cmds;
	char	*linecmds;
	int		i;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			print_error();
		i++;
	}
	if (argc == 2 && !argv[1][0])
		print_error();
	else if (argc == 2)
		cmds = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		linecmds = get_cmd_line(argc, argv);
		cmds = ft_split(linecmds, ' ');
		free(linecmds);
	}
	return (cmds);
}
