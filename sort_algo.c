/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:19:15 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/09 22:40:30 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_3(int *stack_a, int a_len)
{
	if (stack_a[0] > stack_a[1])
		swap_a(stack_a, a_len);
	if (stack_a[1] > stack_a[2])
	{
		rev_rot_a(stack_a, a_len);
		if (stack_a[0] > stack_a[1])
			swap_a(stack_a, a_len);
	}
}

void	stack_4(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	int	i;

	i = 1;
	while (*a_len > i)
	{
		if (stack_a[0] > stack_a[i])
		{
			rotate_a(stack_a, *a_len);
			i = 1;
		}
		else
			i++;
	}
	push_b(stack_a, stack_b, a_len, b_len);
	stack_3(stack_a, *a_len);
	push_a(stack_a, stack_b, a_len, b_len);
}

void	stack_5(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	int	i;

	while (*a_len > 4)
	{
		i = 1;
		while (*a_len > i)
		{
			if (stack_a[0] > stack_a[i])
			{
				rotate_a(stack_a, *a_len);
				i = 1;
			}
			else
				i++;
		}
		push_b(stack_a, stack_b, a_len, b_len);
	}
	stack_4(stack_a, stack_b, a_len, b_len);
	push_a(stack_a, stack_b, a_len, b_len);
}
