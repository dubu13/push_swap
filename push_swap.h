/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:48:00 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/05 20:28:25 by dhasan           ###   ########.fr       */
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

//error_free.c
void				error_msg(void);
void				free_stack(t_stack *stack);
void				free_str(char **str);
//check_args.c
t_stack				*parse_args(int argc, char **argv);
int					check_sorted(t_stack *stack);
void				check_duplicates(t_stack *stack);
//utils.c
int					stack_size(t_stack *stack);
int					ft_atoi2(const char *str);
//stack_utils.c
void				init_index(t_stack *stack);
t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
t_stack				*last_node(t_stack *stack);
void				append_node(t_stack **stack, int value);
//cost_target.c
t_stack				*set_cheapest(t_stack *stack);
void				cost_pa(t_stack *a, t_stack *b);
void				cost_pb(t_stack *a, t_stack *b);
void				target_for_a(t_stack *a, t_stack *b);
void				target_for_b(t_stack *a, t_stack *b);
//sorting.c
void				final_sort(t_stack **a);
void				prep_for_pb(t_stack **a, t_stack **b, t_stack *cheapest);
void				prep_for_pa(t_stack **a, t_stack **b, t_stack *cheapest);
void				push_to_b(t_stack **a, t_stack **b);
void				push_to_a(t_stack **a, t_stack **b);
//rotate.c
void				ra(t_stack **stack, int op);
void				rb(t_stack **stack, int op);
void				rr(t_stack **a, t_stack **b, int op);
//reverse_rotate.c
void				rra(t_stack **stack, int op);
void				rrb(t_stack **stack, int op);
void				rrr(t_stack **a, t_stack **b, int op);
//swap_push.c
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack *stack, int op);
void				sb(t_stack *stack, int op);
void				ss(t_stack **a, t_stack **b, int op);

//


void	ft_print_stack(t_stack *stack);


#endif