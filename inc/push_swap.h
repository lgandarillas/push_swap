/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:45:36 by lgandari          #+#    #+#             */
/*   Updated: 2024/06/14 18:06:53 by lgandari         ###   ########.fr       */
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
	int					push_cost;
	int					over_mid;
	int					smallest_cost;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
}	t_stack_node;

void			print_split(char **str);
void			free_split(char **str);
char			**parser(int argc, char **argv);
char			*parse_cmds(int argc, char **argv);

void			init_stack(t_stack_node **a, char **args);
void			print_error(void);

void			print_stack(t_stack_node *s);
void			free_stack(t_stack_node *s);
int				stack_len(t_stack_node *s);
int				has_duplicates(t_stack_node *s);
void			stack_error(t_stack_node *a, char **args);

t_stack_node	*get_max_node(t_stack_node *s);
t_stack_node	*get_min_node(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *s);
t_stack_node	*get_smallest_cost_node(t_stack_node **a);

int				is_sorted(t_stack_node *s);
void			sort_three(t_stack_node **a);
void			turk_sort(t_stack_node **a, t_stack_node **b);
void			update_stack_a(t_stack_node *a, t_stack_node *b);
void			update_stack_idx(t_stack_node *stack);

void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

void			bring_cheapest_up(t_stack_node **a, t_stack_node **b, \
				t_stack_node *cheapest);
void			reverse_bring_cheapest_up(t_stack_node **a, t_stack_node **b, \
				t_stack_node *cheapest);
void			ensure_cheapest_up(t_stack_node **stack, \
				t_stack_node *cheapest, char s_name);
void			bring_min_up(t_stack_node **a);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
