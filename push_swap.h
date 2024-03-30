/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:48:00 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/30 22:18:53 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"
# include <limits.h>
# include <stdbool.h>

# define DOUBLE_OP '0'
# define SINGLE_OP '1'

typedef struct s_stack
{
	long			value;
	long			index;
	long			cost;
	bool			above_med;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

void	ft_print_stack(t_stack *stack);
//parse_check.c
void	check_duplicates(t_stack *stack);
int		check_sorted(t_stack *stack);
t_stack	*str_case(t_stack *a, int index, char **argv);
t_stack	*parse_args(int argc, char **argv);
//push_op.c
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
//rotate_op.c
void	ra(t_stack *a, int op);
void	rb(t_stack *b, int op);
void	rr(t_stack **a, t_stack **b, int op);
//rev_rotate_op.c
void	rra(t_stack *a, int op);
void	rrb(t_stack *b, int op);
void	rrr(t_stack **a, t_stack **b, int op);
//swap_op.c
void	sa(t_stack *a, int op);
void	sb(t_stack *b, int op);
void	ss(t_stack **a, t_stack **b, int op);
//sort_3.c
void	sort_3(t_stack *stack);

//find_target.c

//cost.c

//stack_utils.c
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*last_node(t_stack *stack);
t_stack	*create_node(int value);
t_stack	*set_cheapest(t_stack *a);
void	append_node(t_stack **stack, int value);
//stack_utils2.c
int		cost_rotate(t_stack *stack, int pos);
int		cost_rev_r(t_stack *stack, int pos);
int		find_pos(t_stack *stack, int value);
//utils.c
void	free_stack(t_stack *stack);
void	free_str(char **str);
int		is_digit(char c);
int		stack_size(t_stack *stack);
int		ft_atoi2(const char *str);
//error.c
void	error_msg(void);
//
void	target_for_a(t_stack *a, t_stack *b);
void	target_for_b(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
void	cost_pa(t_stack *a, t_stack *b);
void	cost_pb(t_stack *a, t_stack *b);
void	init_index(t_stack *stack);
void	push_to_b(t_stack *a, t_stack *b);
void	single_r_op(t_stack *a, t_stack *b, t_stack *cheapest);
#endif