/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:56:34 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 14:35:58 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Returns the largest absolute number if both a and b are positive or negative.
 * Otherwise returns the difference between a and b
 */

int tot_cost(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		a = abs(a);
		b = abs(b);
		if (a > b)
			return (a);
		return (b);
	}
	return abs(a - b);
}

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
		printf("%d b_data [%d]\n", f_arr[i].b_data, i);
		f_arr[i].a_data = determine_friend(*a, f_arr[i].b_data);
		printf("%d a_data [%d]\n", f_arr[i].a_data, i);
		f_arr[i].a_cost = to_top_cost(*a, f_arr[i].a_data);
		printf("%d a cost [%d]\n", f_arr[i].a_cost, i);
		f_arr[i].b_cost = to_top_cost(*b, f_arr[i].b_data);
		printf("%d b cost [%d]\n", f_arr[i].b_cost, i);
		f_arr[i].tot_cost = tot_cost(f_arr[i].a_cost, f_arr[i].b_cost);
		printf("%d tot cost [%d]\n", f_arr[i].tot_cost, i);
		i++;
		curr = curr-> next;
	}
	// printf("\n");
	// for (int j = 0; j < len_b; j++)
	// 	printf("%d tot cost [%d]\n", f_arr[j].tot_cost, j);
	// printf("\n");
	// for (int j = 0; j < len_b; j++)
	// 	printf("%d a_data [%d]\n", f_arr[j].a_data, j);
	// printf("\n");
	// for (int j = 0; j < len_b; j++)
	// 	printf("%d b_data [%d]\n", f_arr[j].b_data, j);
	// printf("\n");
	// for (int j = 0; j < len_b; j++)
	// 	printf("%d a cost [%d]\n", f_arr[j].a_cost, j);
	// printf("\n");
	// for (int j = 0; j < len_b; j++)
	// 	printf("%d b cost [%d]\n", f_arr[j].b_cost, j);
	return (f_arr);
}
