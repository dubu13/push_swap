/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:16:21 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/30 21:32:47 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int op)
{
	t_stack	*tail;
	int		tail_value;

	if (!a || !a->next)
		return ;
	tail = last_node(a);
	tail_value = tail->value;
	while (tail->prev)
	{
		tail->value = tail->prev->value;
		tail = tail->prev;
	}
	tail->value = tail_value;
	if (op == SINGLE_OP)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int op)
{
	t_stack	*tail;
	int		tail_value;

	if (!b || !b->next)
		return ;
	tail = last_node(b);
	tail_value = tail->value;
	while (tail->prev)
	{
		tail->value = tail->prev->value;
		tail = tail->prev;
	}
	tail->value = tail_value;
	if (op == SINGLE_OP)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int op)
{
	rra(*a, op);
	rrb(*b, op);
	if (op == DOUBLE_OP)
		ft_printf("rrr\n");
}
