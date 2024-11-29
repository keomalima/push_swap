/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:10:38 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/29 15:59:43 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nbr_repeat(int ac, char **av)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	while (ac > ++i)
	{
		j = 0;
		while (av[i][j])
		{
			l = j + 1;
			while (av[i][l])
			{
				if (av[i][j] == av[i][l])
					return (ft_printf("Error\n"), 1);
				l++;
			}
			j++;
		}
	}
	return (0);
}

int	is_arg_valid(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (ac > ++i)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
					return (ft_printf("Error\n"), 1);
			j++;
		}
	}
	return (0);
}

int	count_nbrlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}