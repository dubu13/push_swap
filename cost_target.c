/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:51 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/16 12:16:15 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	while (stack != NULL)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	cost_to_pb(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (a)
	{
		a->cost = 0;
		if (a->above_mid)
			a->cost += a->index;
		else
			a->cost += stack_size(temp) - a->index;
		if (a->target->above_mid)
			a->cost += a->target->index;
		else
			a->cost += stack_size(b) - a->target->index;
		a = a->next;
	}
}

void	cost_to_pa(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (b)
	{
		b->cost = 0;
		if (b->above_mid)
			b->cost += b->index;
		else
			b->cost += stack_size(temp) - b->index;
		if (b->target->above_mid)
			b->cost += b->target->index;
		else
			b->cost += stack_size(a) - b->target->index;
		b = b->next;
	}
}

void	target_for_a(t_stack *a, t_stack *b)
{
	int		target_value;
	t_stack	*target;
	t_stack	*temp;

	if (!a)
		return ;
	while (a)
	{
		temp = b;
		target_value = INT_MIN;
		while (temp)
		{
			if (temp->value < a->value && temp->value > target_value)
			{
				target_value = temp->value;
				target = temp;
			}
			temp = temp->next;
		}
		if (target_value == INT_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	target_for_b(t_stack *a, t_stack *b)
{
	int		target_value;
	t_stack	*target;
	t_stack	*temp;

	if (!b)
		return ;
	while (b)
	{
		temp = a;
		target_value = INT_MAX;
		while (temp)
		{
			if (temp->value > b->value && temp->value < target_value)
			{
				target_value = temp->value;
				target = temp;
			}
			temp = temp->next;
		}
		if (target_value == INT_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}
// target for a node is the smaller value than a and closest to a value
// if there no smaller than a, target is the max value in b
//////////////////////////////////////////////////////////////////////
// target for b node is the bigger value than b and closest to b value
// if there no bigger than b, target is the min value in a
//////////////////////////////////////////////////////////////////////
// we wanna push the node above the target node
// cost functions are calculate the how many operations
// has to be done to put node and the target to top of the stack
//////////////////////////////////////////////////////////////////////