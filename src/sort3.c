/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:58:00 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 23:42:40 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Finds cheapest total cost 'tot_cost' from stack b and each node's
 * best friend. Then rotates and pushes the cheapest.
 */

void	find_cheapest(t_friends *t_arr, int b_len, t_stk **a, t_stk **b)
{
	int	i;
	int	lowest_cost;
	int	cheap_index;

	i = 0;
	cheap_index = i;
	lowest_cost = t_arr[i].tot_cost;
	while (i < b_len)
	{
		if (t_arr[i].tot_cost < lowest_cost)
		{
			lowest_cost = t_arr[i].tot_cost;
			cheap_index = i;
		}
		i++;
	}
	push_cheapest(a, b, t_arr, cheap_index);
	free(t_arr);
}
