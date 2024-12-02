/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kricci-d <kricci-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:13:07 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/02 12:44:42 by kricci-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

int		arg_count(int ac, char **av, int *len);
int		stack_parse(int ac, char **av, int *len, int **stack);
int		is_arg_valid(int ac, char **av);
int		parse_args(int ac, char **av, int *stack);
int		split_to_stack(char *av, int *stack, int *error, int *j);
int		validate_unique_stack(int *stack, int len);
int		is_order(int *stack, int len);

void	swap_a(int *stack, int len);
void	swap_b(int *stack, int len);
void	swap_ss(int *stack, int len);
void	push_a(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len);
void	push_b(int *stack_a, int *stack_b, int *stack_a_len, int *stack_b_len);
void	rotate_a(int *stack_a, int stack_a_len);
void	rotate_b(int *stack_b, int stack_b_len);
void	rot_a_b(int *stack_a, int *stack_b, int stack_a_len, int stack_b_len);
void	rev_rot_a(int *stack_a, int stack_a_len);
void	rev_rot_b(int *stack_b, int stack_b_len);
void	rev_rot(int *stack_a, int *stack_b, int stack_a_len, int stack_b_len);

void	stack_3(int *stack_a, int a_len);
void	stack_4(int *stack_a, int *stack_b, int *a_len, int *b_len);

#endif
