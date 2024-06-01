/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:45:36 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/01 16:45:38 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "../libft_v2/inc/libft.h"
# include "../libft_v2/inc/get_next_line.h"
# include "../libft_v2/inc/ft_printf.h"

typedef struct s_stack_node
{
	int					num;
	int					idx;
	int					cost;
	int					over_mid;
	int					cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
}	t_stack_node;

void	print_split(char **str);
void	free_split(char **str);
char	**parser(int argc, char **argv);
char	*parse_cmds(int argc, char **argv);

void	init_stack(t_stack_node **a, char **args);
void	print_error(void);

void	print_stack(t_stack_node *s);
void	free_stack(t_stack_node *s);
int		stack_len(t_stack_node *s);

int		is_sorted(t_stack_node *s);

#endif
