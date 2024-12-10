/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keomalima <keomalima@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:25:26 by kricci-d          #+#    #+#             */
/*   Updated: 2024/12/09 22:40:38 by keomalima        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*find_action(int a_len, int b_len, int position, int index)
{
	int	rr_cost;
	int	rrr_cost;
	int	rota_revb_cost;
	int	reva_rotb_cost;
	int	min;

	rr_cost = rotate_cost(position, index);
	rrr_cost = rev_rotate_cost(a_len, b_len, position, index);
	rota_revb_cost = index + (b_len - position);
	reva_rotb_cost = (a_len - index) + position;
	min = ft_min (rr_cost, rrr_cost, rota_revb_cost, reva_rotb_cost);
	if (min == rr_cost)
		return ("rr");
	else if (min == rrr_cost)
		return ("rrr");
	else if (min == reva_rotb_cost)
		return ("rota_revb");
	else
		return ("reva_rotb");
}
