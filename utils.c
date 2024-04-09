/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:59:42 by dhasan            #+#    #+#             */
/*   Updated: 2024/04/09 20:21:02 by dhasan           ###   ########.fr       */
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

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	check_negative(const char *str)
{
	if (*str == '-' && (*(++str) == '\0' || !is_digit(++str)))
		error_msg();
	if (*str == '+')
		error_msg();
}


int	ft_atoi2(const char *str)
{
	int				sign;
	long long int	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	check_negative(str);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	if (!is_digit(str))
		error_msg();
	while (*str >= '0' && *str <= '9')
		num = (num * 10) + (*str++ - '0');
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		error_msg();
	return (num * sign);
}
