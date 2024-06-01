/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:45:36 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/01 11:42:57 by lgandari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

# include "../libft_v2/inc/libft.h"
# include "../libft_v2/inc/get_next_line.h"
# include "../libft_v2/inc/ft_printf.h"

void	print_split(char **str);
void	free_split(char **str);
char	**parser(int argc, char **argv);
char	*parse_cmds(int argc, char **argv);

void	print_error(void);

typedef struct s_stack_node
{
	int					num;
	int					idx;
	int					cost;
	bool				over_mid;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
}	t_stack_node;

// Error handling

// Stack initiation

// Node initiation

// Stack utils

// Commands
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);

// Algorithms

#endif
