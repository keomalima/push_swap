/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:51:20 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/10 10:30:01 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *stack_a, int stack_a_len)
{
	int	i;
	int	n1;

	if (stack_a_len > 1)
	{
		n1 = stack_a[0];
		i = -1;
		while (stack_a_len > ++i)
			stack_a[i] = stack_a[i + 1];
		stack_a[i - 1] = n1;
		ft_printf("ra\n");
	}
}

void	rotate_b(int *stack_b, int stack_b_len)
{
	int	i;
	int	n1;

	if (stack_b_len > 1)
	{
		n1 = stack_b[0];
		i = -1;
		while (stack_b_len > ++i)
			stack_b[i] = stack_b[i + 1];
		stack_b[i - 1] = n1;
		ft_printf("rb\n");
	}
}

void	rot_a_b(int *stack_a, int *stack_b, int stack_a_len, int stack_b_len)
{
	int	i;
	int	n1;

	if (stack_b_len > 1)
	{
		n1 = stack_b[0];
		i = -1;
		while (stack_b_len > ++i)
			stack_b[i] = stack_b[i + 1];
		stack_b[i - 1] = n1;
	}
	if (stack_a_len > 1)
	{
		n1 = stack_a[0];
		i = -1;
		while (stack_a_len > ++i)
			stack_a[i] = stack_a[i + 1];
		stack_a[i - 1] = n1;
	}
	ft_printf("rr\n");
}
