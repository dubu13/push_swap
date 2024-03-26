/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:47:25 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 21:08:57 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_3node(t_stack *stack)
{
	if (find_max(stack)->value == stack->value)
	{
		ra(stack, SINGLE_OP);
		if (find_min(stack)->value != stack->value)
			sa(stack, SINGLE_OP);
	}
	else if (find_min(stack)->value == stack->value)
	{
		rra(stack, SINGLE_OP);
		sa(stack, SINGLE_OP);
	}
	else if (find_max(stack)->value == last_node(stack)->value)
		sa(stack, SINGLE_OP);
	else
		rra(stack, SINGLE_OP);
	ft_print_stack(stack);
}
