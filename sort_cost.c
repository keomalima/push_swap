/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:30:21 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/09 22:42:47 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(int *stack_b, int b_len, int nbr)
{
	int	i;
	int	position;

	i = 0;
	position = -1;
	while (b_len > i)
	{
		if (nbr > stack_b[i] && (position == -1
				|| stack_b[i] > stack_b[position]))
			position = i;
		i++;
	}
	if (position == -1)
	{
		i = 0;
		position = 0;
		while (b_len - 1 > i)
		{
			if (stack_b[i] < stack_b[i + 1])
				position = i + 1;
			i++;
		}
	}
	return (position);
}

int	ft_min(int a, int b, int c, int d)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

int	rotate_cost(int position, int index)
{
	int	ra_cost;
	int	rb_cost;

	ra_cost = index;
	rb_cost = position;
	if (ra_cost > rb_cost)
		return (ra_cost);
	return (rb_cost);
}

int	rev_rotate_cost(int a_len, int b_len, int position, int index)
{
	int	rra_cost;
	int	rrb_cost;

	rra_cost = a_len - index;
	rrb_cost = b_len - position;
	if (rra_cost > rrb_cost)
		return (rra_cost);
	return (rrb_cost);
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
