/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:36 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/10 10:38:34 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheap_to_b(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	int		cheap_index;
	int		position;
	char	*action;

	while (*a_len > 3)
	{
		cheap_index = cheapest_index(stack_a, stack_b, *a_len, *b_len);
		position = find_position_b(stack_b, *b_len, stack_a[cheap_index]);
		action = find_action(*a_len, *b_len, position, cheap_index);
		if (ft_strncmp(action, "rrr", ft_strlen("rrr")) == 0)
			execute_rrr(stack_a, stack_b, *a_len, *b_len);
		if (ft_strncmp(action, "rr", ft_strlen("rr")) == 0)
			execute_rr(stack_a, stack_b, *a_len, *b_len);
		if (ft_strncmp(action, "rota_revb", ft_strlen("rota_revb")) == 0)
			execute_rota_revb(stack_a, stack_b, *a_len, *b_len);
		if (ft_strncmp(action, "reva_rotb", ft_strlen("reva_rotb")) == 0)
			execute_reva_rotb(stack_a, stack_b, *a_len, *b_len);
		push_b(stack_a, stack_b, a_len, b_len);
	}
}

void	sort_a(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	int	position;

	while (*b_len > 0)
	{
		position = find_position_a(stack_a, *a_len, stack_b[0]);
		if (position > *a_len / 2)
		{
			while (position < *a_len)
			{
				rev_rot_a(stack_a, *a_len);
				position++;
			}
		}
		else
		{
			while (position > 0)
			{
				rotate_a(stack_a, *a_len);
				position--;
			}
		}
		push_a(stack_a, stack_b, a_len, b_len);
	}
}

void	final_sort(int *stack_a, int a_len)
{
	int	i;
	int	min_index;

	min_index = 0;
	i = 0;
	while (++i < a_len)
		if (stack_a[i] < stack_a[min_index])
			min_index = i;
	if (min_index > a_len / 2)
	{
		while (min_index < a_len)
		{
			rev_rot_a(stack_a, a_len);
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			rotate_a(stack_a, a_len);
			min_index--;
		}
	}
}

void	turkish_sort(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	push_b(stack_a, stack_b, a_len, b_len);
	push_b(stack_a, stack_b, a_len, b_len);
	push_cheap_to_b(stack_a, stack_b, a_len, b_len);
	stack_3(stack_a, *a_len);
	sort_a(stack_a, stack_b, a_len, b_len);
	if (is_order(stack_a, *a_len))
		final_sort(stack_a, *a_len);
}
