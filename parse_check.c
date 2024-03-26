/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:49:14 by dhasan            #+#    #+#             */
/*   Updated: 2024/03/25 19:10:45 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	check_duplicates(t_stack *stack)
{
	t_stack	*check;

	if (!stack)
	{
		free_stack(stack);
		error_msg();
	}
	while (stack != NULL)
	{
		check = stack->next;
		while (check != NULL)
		{
			if (stack->value == check->value)
			{
				free_stack(stack);
				error_msg();
			}
			check = check->next;
		}
		stack = stack->next;
	}
}

int	check_sorted(t_stack *stack)
{
	if (!stack)
		error_msg();
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*str_case(t_stack *a, int index, char **argv)
{
	char	**parsed;
	int		value;

	parsed = ft_split(argv[index], ' ');
	while (parsed[index - 1])
	{
		value = ft_atoi2(parsed[index - 1]);
		append_node(&a, value);
		index++;
	}
	free_str(parsed);
	free(parsed);
	return (a);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		index;
	int		value;

	a = NULL;
	index = 1;
	while (index < argc)
	{
		if (argc == 2)
			str_case(a, index, argv);
		else
		{
			value = ft_atoi2(argv[index]);
			append_node(&a, value);
			index++;
		}
	}
	return (a);
}
