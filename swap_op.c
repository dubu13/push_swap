/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:34:43 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/11 17:09:23 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
