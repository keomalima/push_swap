/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:26 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/29 16:03:34 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_len(char **av)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (av[i])
		len += count_nbrlen(ft_atoi(av[i++]));
	return (len);
}

int	main(int ac, char **av)
{
	int	len;
	int i;
	int	*stack_a = NULL;

	if (ac > 1 && is_arg_valid(ac, av))
		return (1);
	len = array_len(av);
	i = 1;
	while (ac > i)
	{
		if (ft_strchr(av[i], 32))
			ft_split(av[i], 32);
	}
	if (!stack_a)
		return (1);
	return (0);
}