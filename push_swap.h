/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:13:07 by keomalima         #+#    #+#             */
/*   Updated: 2024/11/30 17:30:58 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

int		arg_count(int ac, char **av, int *len);
int		stack_parse(int ac, char **av, int *len, int **stack);
int		is_arg_valid(int ac, char **av);
int		parse_args(int ac, char **av, int *stack);
int		split_to_stack(char *av, int *stack, int *error, int *j);
int		validate_unique_stack(int *stack, int len);

#endif