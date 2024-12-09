/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:24:36 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/09 22:59:14 by keomalima        ###   ########.fr       */
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
	int		cheap_index;
	int		position;
	char	*action;

	while (*a_len > 3)
	{
		cheap_index = cheapest_index(stack_b, stack_a, *b_len, *a_len);
		position = find_position(stack_a, *a_len, stack_b[cheap_index]);
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

void	push_cheap_to_a(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	int		cheap_index;
	int		position;
	char	*action;

	while (*b_len > 1)
	{
		cheap_index = cheapest_index(stack_a, stack_b, *a_len, *b_len);
		position = find_position(stack_b, *b_len, stack_a[cheap_index]);
		action = find_action(*a_len, *b_len, position, cheap_index);
		if (ft_strncmp(action, "rrr", ft_strlen("rrr")) == 0)
			execute_rrr(stack_a, stack_b, *a_len, *b_len);
		if (ft_strncmp(action, "rr", ft_strlen("rr")) == 0)
			execute_rr(stack_a, stack_b, *a_len, *b_len);
		if (ft_strncmp(action, "rota_revb", ft_strlen("rota_revb")) == 0)
			execute_rota_revb(stack_a, stack_b, *a_len, *b_len);
		if (ft_strncmp(action, "reva_rotb", ft_strlen("reva_rotb")) == 0)
			execute_reva_rotb(stack_a, stack_b, *a_len, *b_len);
		push_a(stack_a, stack_b, a_len, b_len);
	}
}

void	turkish_sort(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	push_b(stack_a, stack_b, a_len, b_len);
	push_b(stack_a, stack_b, a_len, b_len);
	push_cheap_to_b(stack_a, stack_b, a_len, b_len);
	stack_3(stack_a, *a_len);
	//push_cheap_to_a(stack_a, stack_b, a_len, b_len);
}
