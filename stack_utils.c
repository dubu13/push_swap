/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:42 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/01 13:38:32 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	if (stack)
		max = stack;
	while (stack != NULL)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (stack)
		min = stack;
	while (stack != NULL)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack **stack, int value)
{
	t_stack		*new;
	t_stack		*tail;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		error_msg();
	new->value = value;
	if (!(*stack))
		*stack = new;
	else
	{
		tail = last_node(*stack);
		tail->next = new;
		new->prev = tail;
		new->next = NULL;
	}
}
