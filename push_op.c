/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:46:54 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/30 21:59:50 by dhasan           ###   ########.fr       */
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

