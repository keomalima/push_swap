/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:32:13 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/03 16:27:24 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_a(int *stack_a, int stack_a_len)
{
	int	last_n;

	if (stack_a_len > 1)
	{
		last_n = stack_a[stack_a_len - 1];
		while (stack_a_len > 0)
		{
			stack_a[stack_a_len] = stack_a[stack_a_len - 1];
			stack_a_len--;
		}
		stack_a[0] = last_n;
		ft_printf("rra\n");
	}
}

void	rev_rot_b(int *stack_b, int stack_b_len)
{
	int	last_n;

	if (stack_b_len > 1)
	{
		last_n = stack_b[stack_b_len - 1];
		while (stack_b_len > 0)
		{
			stack_b[stack_b_len] = stack_b[stack_b_len - 1];
			stack_b_len--;
		}
		stack_b[0] = last_n;
		ft_printf("rrb\n");
	}
}

void	rev_rot(int *stack_a, int *stack_b, int stack_a_len, int stack_b_len)
{
	rev_rot_a(stack_a, stack_a_len);
	rev_rot_b(stack_b, stack_b_len);
	ft_printf("rrr\n");
}
