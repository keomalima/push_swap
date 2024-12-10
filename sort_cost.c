/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:30:21 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/10 08:04:21 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
