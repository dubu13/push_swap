/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:51:35 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/15 19:56:32 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int op)
{
	t_stack	*tail;

	if (!*a || !(*a)->next)
		return ;
	tail = last_node(*a);
	tail->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
	if (op == SINGLE_OP)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int op)
{
	t_stack	*tail;

	if (!*b || !(*b)->next)
		return ;
	tail = last_node(*b);
	tail->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tail->next->prev = tail;
	tail->next->next = NULL;
	if (op == SINGLE_OP)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int op)
{
	ra(a, op);
	rb(b, op);
	if (op == DOUBLE_OP)
		ft_printf("rr\n");
}
