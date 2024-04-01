/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:34:43 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/01 13:32:58 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*new_head;

	if (!*b)
		return ;
	new_head = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	new_head->next = *a;
	if (*a)
		(*a)->prev = new_head;
	*a = new_head;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*new_head;

	if (!*a)
		return ;
	new_head = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	new_head->next = *b;
	if (*b)
		(*b)->prev = new_head;
	*b = new_head;
	ft_printf("pb\n");
}

void	sa(t_stack *a, int op)
{
	int	head_value;
	int	second_value;

	if (!a && !a->next)
		return ;
	head_value = a->value;
	second_value = a->next->value;
	a->next->value = head_value;
	a->value = second_value;
	if (op == SINGLE_OP)
		ft_printf("sa\n");
}

void	sb(t_stack *b, int op)
{
	int	head_value;
	int	second_value;

	if (!b && !b->next)
		return ;
	head_value = b->value;
	second_value = b->next->value;
	b->next->value = head_value;
	b->value = second_value;
	if (op == SINGLE_OP)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int op)
{
	sa(*a, op);
	sb(*b, op);
	if (op == DOUBLE_OP)
		ft_printf("ss\n");
}
