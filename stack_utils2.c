/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:44:24 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 22:54:32 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_stack *stack)
{
	int		index;

	index = 0;
	while (stack)
	{
		stack->index = index;
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

// int	cost_rotate(t_stack *stack, int pos)
// {
// 	int	cost;
// 	int	head_pos;

// 	cost = 0;
// 	head_pos = 1;
// 	while (stack && head_pos != pos)
// 	{
// 		stack = stack->next;
// 		head_pos++;
// 		cost++;
// 	}
// 	return (cost);
// }

// int	cost_rev_r(t_stack *stack, int pos)
// {
// 	int	len;

// 	len = stack_size(stack);
// 	return (len - pos + 1);
// }

// int	find_pos(t_stack *stack, int value)
// {
// 	int	pos;

// 	pos = 1;
// 	while (stack && stack->value != value)
// 	{
// 		stack = stack->next;
// 		pos++;
// 	}
// 	return (pos);
// }

