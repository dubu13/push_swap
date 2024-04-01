/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:20:49 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/01 16:03:11 by dhasan           ###   ########.fr       */
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
		printf("A: ");
		ft_print_stack(*a);
		printf("B: ");
		ft_print_stack(*b);
	}
	// sort_3(a);
	while (*b)
	{
		init_index(*a);
		init_index(*b);
		target_for_b(*a, *b);
		cost_pb(*a, *b);
		push_to_a(a, b);
		printf("A: ");
		ft_print_stack(*a);
		printf("B: ");
		ft_print_stack(*b);
	}
	final_sort(a);
	printf("A: ");
	ft_print_stack(*a);
	printf("B: ");
	ft_print_stack(*b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		error_msg();
	else
		a = parse_args(argc, argv);
	check_duplicates(a);
	if (!check_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(a, SINGLE_OP);
		else if (stack_size(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
		printf("A: ");
		ft_print_stack(a);
	}
}
