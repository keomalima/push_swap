/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:26 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/01 18:07:06 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	push_swap(int ac, char**av)
{
	int	*stack_a;
	int	*stack_b;
	int	stack_a_len;
	int	stack_b_len;
	int	i;

	stack_a_len = 0;
	stack_b_len = 0;
	if (stack_parse(ac, av, &stack_a_len, &stack_a))
		return (1);
	stack_b = calloc(stack_a_len, sizeof(int));
	if (!stack_b)
		return (1);
	i = 0;
	push_b(stack_a, stack_b, &stack_a_len, &stack_b_len);
	push_b(stack_a, stack_b, &stack_a_len, &stack_b_len);
	push_a(stack_a, stack_b, &stack_a_len, &stack_b_len);
	ft_printf("Stack_a\n");
	while (stack_a_len > i)
		ft_printf("[%i]", stack_a[i++]);
	free(stack_a);
	i = 0;
	ft_printf("\nStack_b\n");
	while (stack_b_len > i)
		ft_printf("[%i]", stack_b[i++]);
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
