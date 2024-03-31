/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/31 23:14:17 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	prep_push(t_stack **a, t_stack **b, t_stack *cheapest, char t_n)
{
	while (cheapest != *a)
	{
		if (!cheapest->above_med)
			rra(a, SINGLE_OP);
		else
			ra(a, SINGLE_OP);
	}
	while (cheapest->target != *b && t_n == 'b')
	{
		if (!cheapest->target->above_med)
			rrb(b, SINGLE_OP);
		if (cheapest->target->above_med)
			rb(b, SINGLE_OP);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = set_cheapest(*a);
	if (cheapest->above_med && cheapest->target->above_med)
	{
		while (cheapest != *a && cheapest->target != *b)
			rr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	if (!cheapest->above_med && !cheapest->target->above_med)
	{
		while (cheapest != *a && cheapest->target != *b)
			rrr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	prep_push(a, b, cheapest, 'b');
	ft_printf("after single_r_op\n");
	ft_print_stack(*a);
	ft_print_stack(*b);
	pb(a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = set_cheapest(*b);
	if (cheapest->above_med && cheapest->target->above_med)
	{
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	if (!cheapest->above_med && !cheapest->target->above_med)
	{
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	prep_push(a, b, cheapest, 'a');
	ft_print_stack(*a);
	ft_print_stack(*b);
	pa(a, b);
}
