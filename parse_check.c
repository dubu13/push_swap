/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:49:14 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/15 20:03:42 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *stack)
{
	t_stack	*check;
	t_stack	*temp;

	if (!stack)
		free_stack(stack, true);
	temp = stack;
	while (temp != NULL)
	{
		check = temp->next;
		while (check != NULL)
		{
			if (temp->value == check->value)
				free_stack(stack, true);
			check = check->next;
		}
		temp = temp->next;
	}
}

int	check_sorted(t_stack *stack)
{
	if (!stack)
		free_stack(stack, true);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*parse_args(int argc, char **argv, bool *error)
{
	t_stack	*a;
	char	**parsed;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		parsed = ft_split(argv[i], ' ');
		if (!*parsed)
			*error = true;
		j = 0;
		while (parsed[j])
		{
			append_node(&a, ft_atoi2(parsed[j], error));
			j++;
		}
		free_str(parsed);
		i++;
	}
	if (*error)
		free_stack(a, true);
	return (a);
}
