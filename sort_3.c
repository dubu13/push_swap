/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:47:25 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/30 22:42:47 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_3(t_stack *stack)
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
}

void	sort(t_stack *a, t_stack *b)
{
	if (stack_size(a) > 3)
		pb(&a, &b);
	if (stack_size(a) > 3)
		pb(&a, &b);
	ft_print_stack(a);
	ft_print_stack(b);
	printf("stack_size(a) = %d\n", stack_size(a));
	while (stack_size(a) > 3 && !check_sorted(a))
	{
		init_index(a);
		init_index(b);
		target_for_a(a, b);
		cost_pa(a, b);
		push_to_b(a, b);
		ft_print_stack(a);
		ft_print_stack(b);
	}
	sort_3(a);
	ft_print_stack(a);
	ft_print_stack(b);
	// while (b)
	// {
	// 	init_index(a);
	// 	init_index(b);
	// 	target_for_b(a, b);
	// 	cost_pb(a, b);
	// 	// push_to_a(a, b);
	// }
}
