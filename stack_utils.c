/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:42 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 19:37:15 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		error_msg();
	new_node->value = value;
	return (new_node);
}

void	append_node(t_stack **stack, int value)
{
	t_stack		*new;
	t_stack		*tail;

	new = create_node(value);
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
