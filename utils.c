/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:42 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/16 10:51:43 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int	is_digit(const char *str, bool *error)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			*error = true;
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_minus_plus(const char *str, bool *error)
{
	if (*str == '-' && (*(str + 1) == '0' || *(str + 1) == '\0'))
		*error = true;
	if (*str == '-' && !is_digit(++str, error))
		*error = true;
	if (*str == '+')
		*error = true;
}

int	ft_atoi2(const char *str, bool *error)
{
	int				sign;
	long long int	num;

	sign = 1;
	num = 0;
	check_minus_plus(str, error);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	is_digit(str, error);
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*str++ - '0');
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		*error = true;
	return (num * sign);
}
