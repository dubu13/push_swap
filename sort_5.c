/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/30 22:14:39 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	single_r_op(t_stack *a, t_stack *b, t_stack *cheapest)
{
	while (cheapest != a)
	{
		if (!cheapest->above_med)
			rra(a, SINGLE_OP);
		else
			ra(a, SINGLE_OP);
	}
	while (cheapest->target != b)
	{
		if (!cheapest->target->above_med)
			rrb(b, SINGLE_OP);
		else
			rb(b, SINGLE_OP);
	}
}

void	push_to_b(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;

	cheapest = set_cheapest(a);
	if (cheapest->above_med && cheapest->target->above_med)
	{
		while (cheapest != a && cheapest->target != b)
			rr(&a, &b, DOUBLE_OP);
		init_index(a);
		init_index(b);
	}
	if (!cheapest->above_med && !cheapest->target->above_med)
	{
		while (cheapest != a && cheapest->target != b)
			rrr(&a, &b, DOUBLE_OP);
		init_index(a);
		init_index(b);
	}
	single_r_op(a, b, cheapest);
	pb(&a, &b);
}

void	push_to_a(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;

	cheapest = set_cheapest(b);
	if (cheapest->above_med && cheapest->target->above_med)
	{
		while (cheapest != b && cheapest->target != a)
			rr(&a, &b, DOUBLE_OP);
		init_index(a);
		init_index(b);
	}
	if (!cheapest->above_med && !cheapest->target->above_med)
	{
		while (cheapest != b && cheapest->target != a)
			rrr(&a, &b, DOUBLE_OP);
		init_index(a);
		init_index(b);
	}
	single_r_op(b, a, cheapest);
	pa(&a, &b);
}
