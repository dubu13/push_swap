/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:51 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/28 15:03:13 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_pa(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (a)
	{
		a->cost = 0;
		if (a->index <= stack_size(a) / 2)
			a->cost += a->index;
		else
			a->cost += stack_size(temp) - a->index;
		if (a->target->index <= stack_size(b) / 2)
			a->cost += a->target->index;
		else
			a->cost += stack_size(b) - a->target->index;
		a = a->next;
	}
}

void	cost_pb(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (b)
	{
		b->cost = 0;
		if (b->index <= stack_size(b) / 2)
			b->cost += b->index;
		else
			b->cost += stack_size(temp) - b->index;
		if (b->target->index <= stack_size(a) / 2)
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
