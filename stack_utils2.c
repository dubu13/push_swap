/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:44:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/31 18:26:55 by dhasan           ###   ########.fr       */
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

void	init_index(t_stack *stack)
{
	int		index;
	int		mid_p;

	index = 0;
	mid_p = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (stack->index <= mid_p)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		index++;
	}
}

int	cost_rotate(t_stack *stack, int index)
{
	t_stack	*temp;
	int		cost;

	cost = 0;
	temp = stack;
	while (temp && stack->index != index)
	{
		cost++;
		temp = temp->next;
	}
	return (cost);
}

int	cost_rev_r(t_stack *stack, int index)
{
	int	len;

	len = stack_size(stack);
	return (len - index + 1);
}


