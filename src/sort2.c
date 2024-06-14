/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:56:34 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/13 21:36:52 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 * Populates f_arr with all fields.
 * tot_cost is the absolute value of a_cost - b_cost. Accounts for shared operations.
 */

t_friends *build_f_array(t_stk **a, t_stk **b)
{
	int len_b;
	t_friends *f_arr;
	t_stk *curr;
	int i;

	i = 0;
	len_b = list_len(*b);
	f_arr = allocate_f_array(len_b);
	curr = (*b);
	while (i < len_b)
	{
		f_arr[i].b_data = curr->content;
		f_arr[i].a_data = determine_friend(*a, f_arr[i].b_data);
		f_arr[i].a_cost = to_top_cost(*a, f_arr[i].a_data);
		f_arr[i].b_cost = to_top_cost(*b, f_arr[i].b_data);
		f_arr[i].tot_cost = abs(f_arr[i].a_cost - f_arr[i].b_cost);
		i++;
		curr = curr-> next;
	}
	return (f_arr);
}
