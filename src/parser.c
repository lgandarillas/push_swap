/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 09:42:09 by lgandari          #+#    #+#             */
/*   Updated: 2024/05/04 10:16:19 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*parse_cmds(int argc, char **argv)
{
	int		i;
	char	*new;
	char	*withspace;
	char	*result;

	i = 2;
	result = ft_strdup(argv[1]);
	if (!result)
		return (NULL);
	if (argc > 2)
	{
		while (i < argc)
		{
			withspace = ft_strjoin(result, " ");
			new = ft_strjoin(withspace, argv[i]);
			free(withspace);
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
