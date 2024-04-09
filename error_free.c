/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:54:20 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/09 19:35:55 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack->next;
		free (stack);
		stack = temp;
	}
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

