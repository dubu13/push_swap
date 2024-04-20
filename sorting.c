/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/16 13:18:28 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	init_index(*a);
	if (check_sorted(*a))
		return ;
	while (min != *a)
	{
		if (min->above_mid)
			ra(a, SINGLE_OP);
		else
			rra(a, SINGLE_OP);
	}
}

void	prep_for_pb(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest != *a)
	{
		if (!cheapest->above_mid)
			rra(a, SINGLE_OP);
		else
			ra(a, SINGLE_OP);
	}
	while (cheapest->target != *b)
	{
		if (!cheapest->target->above_mid)
			rrb(b, SINGLE_OP);
		if (cheapest->target->above_mid)
			rb(b, SINGLE_OP);
	}
}

void	prep_for_pa(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (cheapest != *b)
	{
		if (!cheapest->above_mid)
			rrb(b, SINGLE_OP);
		else
			rb(b, SINGLE_OP);
	}
	while (cheapest->target != *a)
	{
		if (!cheapest->target->above_mid)
			rra(a, SINGLE_OP);
		if (cheapest->target->above_mid)
			ra(a, SINGLE_OP);
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = set_cheapest(*a);
	if (cheapest->above_mid && cheapest->target->above_mid)
	{
		while (cheapest != *a && cheapest->target != *b)
			rr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	if (!cheapest->above_mid && !cheapest->target->above_mid)
	{
		while (cheapest != *a && cheapest->target != *b)
			rrr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	prep_for_pb(a, b, cheapest);
	pb(a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = set_cheapest(*b);
	if (cheapest->above_mid && cheapest->target->above_mid)
	{
		while (cheapest != *b && cheapest->target != *a)
			rr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	if (!cheapest->above_mid && !cheapest->target->above_mid)
	{
		while (cheapest != *b && cheapest->target != *a)
			rrr(a, b, DOUBLE_OP);
		init_index(*a);
		init_index(*b);
	}
	prep_for_pa(a, b, cheapest);
	pa(a, b);
}
