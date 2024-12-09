/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:13:07 by keomalima         #+#    #+#             */
/*   Updated: 2024/12/09 22:37:37 by keomalima        ###   ########.fr       */
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
void	print_stacks(int *stack_a, int *stack_b, int a_len, int b_len);
void	stack_5(int *stack_a, int *stack_b, int *a_len, int *b_len);

void	turkish_sort(int *stack_a, int *stack_b, int *a_len, int *b_len);
int		cheapest_index(int *stack_a, int *stack_b, int a_len, int b_len);
int		rev_rotate_cost(int a_len, int b_len, int position, int index);
int		rotate_cost(int position, int index);
int		ft_min(int a, int b, int c, int d);
int		find_cheapest(int a_len, int b_len, int position, int index);
int		find_position(int *stack_b, int b_len, int nbr);
char	*find_action(int a_len, int b_len, int position, int index);

void	execute_rrr(int *stack_a, int *stack_b, int a_len, int b_len);
void	execute_rr(int *stack_a, int *stack_b, int a_len, int b_len);
void	execute_reva_rotb(int *stack_a, int *stack_b, int a_len, int b_len);
void	execute_rota_revb(int *stack_a, int *stack_b, int a_len, int b_len);

#endif
