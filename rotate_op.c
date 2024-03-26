/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:51:35 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 21:47:15 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int op)
{
	t_stack	*tail;
	int		head_value;

	if (!a || !a->next)
		return ;
	tail = last_node(a);
	head_value = a->value;
	while (a->next)
	{
		a->value = a->next->value;
		a = a->next;
	}
	tail->value = head_value;
	if (op == SINGLE_OP)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int op)
{
	t_stack	*tail;
	int		head_value;

	if (!b || !b->next)
		return ;
	tail = last_node(b);
	head_value = b->value;
	while (b->next)
	{
		b->value = b->next->value;
		b = b->next;
	}
	tail->value = head_value;
	if (op == SINGLE_OP)
		ft_printf("ra\n");
}

void	rr(t_stack **a, t_stack **b, int op)
{
	ra(*a, op);
	rb(*b, op);
}
