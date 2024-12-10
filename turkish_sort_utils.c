/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:03:32 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/10 11:00:21 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*find_action(int a_len, int b_len, int position, int index)
{
	int	rr_cost;
	int	rrr_cost;
	int	rota_revb_cost;
	int	reva_rotb_cost;
	int	min;

	rr_cost = rotate_cost(position, index);
	rrr_cost = rev_rotate_cost(a_len, b_len, position, index);
	rota_revb_cost = index + (b_len - position);
	reva_rotb_cost = (a_len - index) + position;
	min = ft_min (rr_cost, rrr_cost, rota_revb_cost, reva_rotb_cost);
	if (min == rr_cost)
		return ("rr");
	else if (min == rrr_cost)
		return ("rrr");
	else if (min == reva_rotb_cost)
		return ("reva_rotb");
	else
		return ("rota_revb");
}

int	find_cheapest(int a_len, int b_len, int position, int index)
{
	int	rr_cost;
	int	rrr_cost;
	int	rota_revb_cost;
	int	reva_rotb_cost;

	rr_cost = rotate_cost(position, index);
	rrr_cost = rev_rotate_cost(a_len, b_len, position, index);
	rota_revb_cost = index + (b_len - position);
	reva_rotb_cost = (a_len - index) + position;
	return (ft_min (rr_cost, rrr_cost, rota_revb_cost, reva_rotb_cost));
}

int	find_position_b(int *stack, int len, int nbr)
{
	int	i;
	int	position;

	i = 0;
	position = -1;
	while (len > i)
	{
		if (nbr > stack[i] && (position == -1
				|| stack[i] > stack[position]))
			position = i;
		i++;
	}
	if (position == -1)
	{
		i = 0;
		position = 0;
		while (len - 1 > i)
		{
			if (stack[i] < stack[i + 1])
				position = i + 1;
			i++;
		}
	}
	return (position);
}

int	find_position_a(int *stack, int len, int nbr)
{
	int	i;
	int	position;

	i = 0;
	position = -1;
	while (i < len)
	{
		if (nbr < stack[i] && (position == -1 || stack[i] < stack[position]))
			position = i;
		i++;
	}
	if (position == -1)
	{
		i = 0;
		position = 0;
		while (i < len)
		{
			if (stack[i] > stack[position])
				position = i;
			i++;
		}
		position = (position + 1) % len;
	}
	return (position);
}

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
				find_position_b(stack_b, b_len, stack_a[i]), i);
		if (cheapest > cost)
		{
			cheapest = cost;
			index = i;
		}
		i++;
	}
	return (index);
}
