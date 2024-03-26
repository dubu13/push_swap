/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:05:51 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 22:45:49 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost(t_stack *a, t_stack *b)
{
	
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
