/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:17:14 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/01 21:54:53 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack, int len)
{
	int	i;

	if (len > 1)
	{
		i = stack[0];
		stack[0] = stack[1];
		stack[1] = i;
		ft_printf("sa\n");
	}
}

void	swap_b(int *stack, int len)
{
	int	i;

	if (len > 1)
	{
		i = stack[0];
		stack[0] = stack[1];
		stack[1] = i;
		ft_printf("sb\n");
	}
}

void	swap_ss(int *stack, int len)
{
	swap_a(stack, len);
	swap_b(stack, len);
	ft_printf("ss\n");
}
