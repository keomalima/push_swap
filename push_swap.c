/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:26 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/10 10:39:08 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_order(int *stack, int len)
{
	int	i;

	i = 0;
	if (*stack)
	{
		while (len - 1 > i)
		{
			if (stack[i] > stack[i + 1])
				return (1);
			i++;
		}
	}
	return (0);
}

int	stack_parse(int ac, char **av, int *len, int **stack)
{
	if (arg_count(ac, av, len))
		return (1);
	*stack = ft_calloc(*len, sizeof(int));
	if (!*stack)
		return (1);
	if (parse_args(ac, av, *stack))
		return (free(*stack), 1);
	if (validate_unique_stack(*stack, *len))
		return (free(*stack), 1);
	return (0);
}

static void	algo_parse(int *stack_a, int *stack_b, int *a_len, int *b_len)
{
	if (is_order(stack_a, *a_len))
	{
		if (*a_len == 2)
			swap_a(stack_a, *a_len);
		if (*a_len == 3)
			stack_3(stack_a, *a_len);
		if (*a_len == 4)
			stack_4(stack_a, stack_b, a_len, b_len);
		if (*a_len > 4)
			turkish_sort(stack_a, stack_b, a_len, b_len);
	}
}

int	push_swap(int ac, char**av)
{
	int	*stack_a;
	int	*stack_b;
	int	stack_a_len;
	int	stack_b_len;

	stack_a_len = 0;
	stack_b_len = 0;
	if (stack_parse(ac, av, &stack_a_len, &stack_a))
		return (1);
	stack_b = calloc(stack_a_len, sizeof(int));
	if (!stack_b)
		return (1);
	algo_parse(stack_a, stack_b, &stack_a_len, &stack_b_len);
	free(stack_a);
	free(stack_b);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1 && is_arg_valid(ac, av))
		return (ft_printf("Error\n"), 1);
	if (push_swap(ac, av))
		return (ft_printf("Error\n"), 1);
	return (0);
}
