/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:46:54 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 21:51:16 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*new_head;

	if (!*b)
		return ;
	new_head = create_node((*b)->value);
	new_head->next = *a;
	*a = new_head;
	*b = (*b)->next;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*new_head;

	if (!*a)
		return ;
	new_head = create_node((*a)->value);
	new_head->next = *b;
	*b = new_head;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	ft_printf("pb\n");
}

