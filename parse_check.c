/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:49:14 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/09 18:33:24 by dhasan           ###   ########.fr       */
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

t_stack	*str_case(t_stack *a, int index, char *str)
{
	char	**parsed;
	int		value;

	parsed = ft_split(&str[index], ' ');
	while (parsed[index])
	{
		value = ft_atoi2(parsed[index]);
		append_node(&a, value);
		index++;
	}
	free_str(parsed);
	return (a);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		value;

	a = NULL;
	i = 1;
	if (argc == 2)
	{
		a = str_case(a, i - 1, argv[1]);
		if (!a)
			exit(1);
	}
	else
	{
		while (i < argc)
		{
			value = ft_atoi2(argv[i]);
			append_node(&a, value);
			i++;
		}
	}
	return (a);
}
