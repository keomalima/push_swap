/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:19:15 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/10 10:39:52 by kricci-d         ###   ########.fr       */
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
