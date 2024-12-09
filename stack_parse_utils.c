/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:10:38 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/09 22:38:27 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(int *stack_a, int *stack_b, int stack_a_len, int stack_b_len)
{
	int	i;

	i = 0;
	if (stack_a[0])
	{
		ft_printf("Stack_a\n");
		while (stack_a_len > i)
			ft_printf("[%i]", stack_a[i++]);
		i = 0;
	}
	if (stack_b[0])
	{
		ft_printf("\nStack_b\n");
		while (stack_b_len > i)
			ft_printf("[%i]", stack_b[i++]);
		ft_printf("\n");
	}
}

int	validate_unique_stack(int *stack, int len)
{
	int	i;
	int	j;

	i = -1;
	while (len > ++i)
	{
		j = i + 1;
		while (len > j)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
	}
	return (0);
}

int	split_to_stack(char *av, int *stack, int *error, int *j)
{
	char	**tab;
	char	**temp;

	tab = NULL;
	tab = ft_split(av, 32);
	if (!tab)
		return (1);
	temp = tab;
	while (*tab)
	{
		stack[(*j)++] = ft_atoi(*tab, error);
		if (*error)
		{
			while (*tab)
				free(*tab++);
			return (free(temp), 1);
		}
		free(*tab++);
	}
	free(temp);
	return (0);
}

int	parse_args(int ac, char **av, int *stack)
{
	int		i;
	int		j;
	int		error;

	i = 0;
	j = 0;
	error = 0;
	while (ac > ++i)
	{
		if (ft_strchr(av[i], 32))
		{
			if (split_to_stack(av[i], stack, &error, &j))
				return (1);
		}
		else
		{
			stack[j++] = ft_atoi(av[i], &error);
			if (error)
				return (1);
		}
	}
	return (0);
}

int	arg_count(int ac, char **av, int *len)
{
	int		i;
	char	**tab;
	char	**temp;

	i = 0;
	while (ac > ++i)
	{
		tab = NULL;
		if (ft_strchr(av[i], 32))
		{
			tab = ft_split(av[i], 32);
			temp = tab;
			if (!tab)
				return (1);
			while (*tab)
			{
				(*len)++;
				free(*tab++);
			}
			free(temp);
		}
		else
			(*len)++;
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
		while (av[i][j])
		{
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (1);
			while (av[i][j] && ft_isdigit(av[i][j]))
				j++;
			while (av[i][j] && av[i][j] == ' ')
				j++;
		}
	}
	return (0);
}
