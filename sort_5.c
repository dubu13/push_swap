/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/28 15:58:05 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*cheapest(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*cheapest;

	temp = stack;
	cheapest = stack;
	while (stack)
	{
		if (stack->cost < cheapest->cost)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);

}

void	try(t_stack *a, t_stack *b)
{
	pb(&a, &b);
	pb(&a, &b);
	ft_print_stack(a);
	ft_print_stack(b);
	init_index(a);
	init_index(b);
	target_for_a(a, b);
	cost_pa(a, b);
	cheapest(a);
	target_for_b(a, b);
}

