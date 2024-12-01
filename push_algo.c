/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:46:42 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/01 21:30:25 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len)
{
	int	i;
	int	temp;

	if (*stack_b_len > 0)
	{
		temp = *stack_a_len;
		while (temp > 0)
		{
			stack_a[temp] = stack_a[temp - 1];
			temp--;
		}
		stack_a[0] = stack_b[0];
		i = -1;
		while (*stack_b_len > ++i)
			stack_b[i] = stack_b[i + 1];
		stack_b[i] = 0;
		(*stack_b_len)--;
		(*stack_a_len)++;
		ft_printf("pa\n");
	}
}

void	push_b(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len)
{
	int	i;
	int	temp;

	if (*stack_a_len > 0)
	{
		temp = *stack_b_len;
		while (temp > 0)
		{
			stack_b[temp] = stack_b[temp - 1];
			temp--;
		}
		stack_b[0] = stack_a[0];
		i = -1;
		while (*stack_a_len - 1 > ++i)
			stack_a[i] = stack_a[i + 1];
		stack_a[i] = 0;
		(*stack_a_len)--;
		(*stack_b_len)++;
		ft_printf("pb\n");
	}
}
