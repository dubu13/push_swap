/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:13 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/26 22:08:51 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	try(t_stack *a, t_stack *b)
{
	pb(&a, &b);
	pb(&a, &b);
	ft_print_stack(a);
	ft_print_stack(b);
	target_for_a(a, b);
	target_for_b(a, b);
}

// void	sort_5node(t_stack *a, t_stack *b)
// {
// 	int	min_pos;
// 	int	head_pos;
// 	int	i;

// 	while (stack_size(a) > 3)
// 	{
// 		i = 0;
// 		head_pos = 1;
// 		min_pos = find_pos(a, find_min(a));
// 		if (cost_rev_r(a, min_pos) > cost_rotate(a, min_pos))
// 			while (head_pos++ != min_pos)
// 				ra(a, SINGLE_OP);
// 		else
// 			while ((min_pos + i++) != stack_size(a) + 1)
// 				rra(a, SINGLE_OP);
// 		if (check_sorted(a) && stack_size(b) == 0)
// 			return ;
// 		pb(&a, &b);
// 		ft_print_stack(a);
// 		ft_print_stack(b);
// 	}
// 	sort_3node(a);
// 	pa(&a, &b);
// 	pa(&a, &b);
// 	ft_print_stack(a);
// 	ft_print_stack(b);
// }
