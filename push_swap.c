/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:26 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/30 17:31:48 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_parse(int ac, char **av, int *len, int **stack)
{
	if (arg_count(ac, av, len))
		return (1);
	*stack = ft_calloc(*len + 1, sizeof(int));
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
	int	*temp;
	int	len;

	stack_a = NULL;
	len = 0;
	if (stack_parse(ac, av, &len, &stack_a))
		return (1);
	temp = stack_a;
	int i = 0;
	while (len > i)
		ft_printf("[%i]", stack_a[i++]);
	free(temp);
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