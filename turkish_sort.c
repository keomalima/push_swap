/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:36 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/09 17:25:59 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cheapest_index(int *stack_a, int *stack_b, int a_len, int b_len)
{
	int	cost;
	int	i;
	int	cheapest;
	int	index;

	cheapest = INT_MAX;
	i = 0;
	while (a_len > i)
	{
		cost = find_cheapest(a_len, b_len,
				find_position(stack_b, b_len, stack_a[i]), i);
		if (cheapest > cost)
		{
			cheapest = cost;
			index = i;
		}
		i++;
	}
	return (index);
}

void	push_cheap_to_b(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	int	cheap_index;

	while (*a_len > 3)
	{
		cheap_index = cheapest_index(stack_a, stack_b, *a_len, *b_len);
		//get instructions to push the cheap_index to b
		//execute instructions
	}
}

void	turkish_sort(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	push_b(stack_a, stack_b, a_len, b_len);
	push_b(stack_a, stack_b, a_len, b_len);
	push_cheap_to_b(stack_a, stack_b, a_len, b_len);
}
