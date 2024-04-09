/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:20:49 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/09 20:55:16 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%ld ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	sort_3(t_stack **stack)
{
	if (find_max(*stack)->value == (*stack)->value)
	{
		ra(stack, SINGLE_OP);
		if (find_min(*stack)->value != (*stack)->value)
			sa(*stack, SINGLE_OP);
	}
	else if (find_min(*stack)->value == (*stack)->value)
	{
		rra(stack, SINGLE_OP);
		sa(*stack, SINGLE_OP);
	}
	else if (find_max(*stack)->value == last_node(*stack)->value)
		sa(*stack, SINGLE_OP);
	else
		rra(stack, SINGLE_OP);
}

void	sort_5(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		init_index(*a);
		if (find_min(*a)->above_med)
		{
			while (find_min(*a)->index != (*a)->index)
				ra(a, SINGLE_OP);
		}
		else
			while (find_min(*a)->index != (*a)->index)
				rra(a, SINGLE_OP);
		pb(a, b);
	}
	if (!check_sorted(*a))
		sort_3(a);
	while (*b)
		pa(a, b);
	// // ft_print_stack(*a);
	// // ft_print_stack(*b);
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_size(*a) > 3)
		pb(a, b);
	if (stack_size(*a) > 3)
		pb(a, b);
	while (stack_size(*a) > 1 && !check_sorted(*a))
	{
		init_index(*a);
		init_index(*b);
		target_for_a(*a, *b);
		cost_pa(*a, *b);
		push_to_b(a, b);
	}
	while (*b)
	{
		init_index(*a);
		init_index(*b);
		target_for_b(*a, *b);
		cost_pb(*a, *b);
		push_to_a(a, b);
	}
	final_sort(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else
		a = parse_args(argc, argv);
	check_duplicates(a);
	if (!check_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(a, SINGLE_OP);
		else if (stack_size(a) == 3)
			sort_3(&a);
		else if (stack_size(a) == 5)
			sort_5(&a, &b);
		else
			sort(&a, &b);
	}
	free_stack(a);
	free_stack(b);
}
