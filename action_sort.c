/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:41:39 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/10 10:32:36 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_reva_rotb(int *stack_a, int *stack_b, int a_len, int b_len)
{
	int	rra_cost;
	int	rb_cost;
	int	position;
	int	index;

	index = cheapest_index(stack_a, stack_b, a_len, b_len);
	position = find_position_b(stack_b, b_len, stack_a[index]);
	rra_cost = a_len - index;
	rb_cost = position;
	while (rra_cost > 0)
	{
		rev_rot_a(stack_a, a_len);
		rra_cost--;
	}
	while (rb_cost > 0)
	{
		rotate_b(stack_b, b_len);
		rb_cost--;
	}
}

void	execute_rota_revb(int *stack_a, int *stack_b, int a_len, int b_len)
{
	int	ra_cost;
	int	rrb_cost;
	int	position;
	int	index;

	index = cheapest_index(stack_a, stack_b, a_len, b_len);
	position = find_position_b(stack_b, b_len, stack_a[index]);
	ra_cost = index;
	rrb_cost = b_len - position;
	while (ra_cost > 0)
	{
		rotate_a(stack_a, a_len);
		ra_cost--;
	}
	while (rrb_cost > 0)
	{
		rev_rot_b(stack_b, b_len);
		rrb_cost--;
	}
}

void	execute_rr(int *stack_a, int *stack_b, int a_len, int b_len)
{
	int	ra_cost;
	int	rb_cost;
	int	position;
	int	index;

	index = cheapest_index(stack_a, stack_b, a_len, b_len);
	position = find_position_b(stack_b, b_len, stack_a[index]);
	ra_cost = index;
	rb_cost = position;
	while (ra_cost > 0 && rb_cost > 0)
	{
		rot_a_b(stack_a, stack_b, a_len, b_len);
		ra_cost--;
		rb_cost--;
	}
	while (ra_cost > 0)
	{
		rotate_a(stack_a, a_len);
		ra_cost--;
	}
	while (rb_cost > 0)
	{
		rotate_b(stack_b, b_len);
		rb_cost--;
	}
}

void	execute_rrr(int *stack_a, int *stack_b, int a_len, int b_len)
{
	int	rra_cost;
	int	rrb_cost;
	int	position;
	int	index;

	index = cheapest_index(stack_a, stack_b, a_len, b_len);
	position = find_position_b(stack_b, b_len, stack_a[index]);
	rra_cost = a_len - index;
	rrb_cost = b_len - position;
	while (rra_cost > 0 && rrb_cost > 0)
	{
		rev_rot(stack_a, stack_b, a_len, b_len);
		rra_cost--;
		rrb_cost--;
	}
	while (rra_cost > 0)
	{
		rev_rot_a(stack_a, a_len);
		rra_cost--;
	}
	while (rrb_cost > 0)
	{
		rev_rot_b(stack_b, b_len);
		rrb_cost--;
	}
}
