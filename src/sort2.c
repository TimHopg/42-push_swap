/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:56:34 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 22:57:51 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	diff_sign(t_stk **a, t_stk **b, int a_c, int b_c);
static void	same_sign(t_stk **a, t_stk **b, int a_c, int b_c);

/*
 * Returns the largest absolute number if both a and b are positive or negative.
 * Otherwise returns the difference between a and b
 */

int	tot_cost(int a, int b)
{
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
	{
		a = abs(a);
		b = abs(b);
		if (a > b)
			return (a);
		return (b);
	}
	return (abs(a - b));
}

/*
 * Populates f_arr with all fields.
 * tot_cost is the absolute value of a_cost
	- b_cost. Accounts for shared operations.
 */

t_friends	*build_f_array(t_stk **a, t_stk **b)
{
	int			len_b;
	t_friends	*f_arr;
	t_stk		*curr;
	int			i;

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
		f_arr[i].tot_cost = tot_cost(f_arr[i].a_cost, f_arr[i].b_cost);
		i++;
		curr = curr->next;
	}
	return (f_arr);
}

/*
 * Prepares stacks for cheapest push from b to when both moves to get a and b to
 * the top are positive or both moves are negative.
 */

static void	same_sign(t_stk **a, t_stk **b, int a_c, int b_c)
{
	int		n;
	void	(*op_func)(t_stk **, t_stk **, char);

	n = 0;
	op_func = op_r;
	if (a_c <= 0 && b_c <= 0)
		op_func = op_rr;
	if (abs(a_c) > abs(b_c))
		n = abs(b_c);
	else
		n = abs(a_c);
	while (n-- > 0)
		stk_mod(op_func, a, b, 'r');
	n = 0;
	if (abs(a_c) >= abs(b_c))
		while (n++ < abs(a_c - b_c))
			stk_mod(op_func, a, b, 'a');
	else
		while (n++ < abs(b_c - a_c))
			stk_mod(op_func, a, b, 'b');
}

/*
 * Prepares stacks for cheapest push from b to when moves to get a and b to the
 * top of their respective stack are different i.e. one is 'rr' and one is 'r'.
 */

static void	diff_sign(t_stk **a, t_stk **b, int a_c, int b_c)
{
	int	n;

	n = 0;
	if (a_c > 0)
		while (n++ < a_c)
			stk_mod(op_r, a, b, 'a');
	else
		while (n-- > a_c)
			stk_mod(op_rr, a, b, 'a');
	n = 0;
	if (b_c > 0)
		while (n++ < b_c)
			stk_mod(op_r, a, b, 'b');
	else
		while (n-- > b_c)
			stk_mod(op_rr, a, b, 'b');
}

/*
 * Moves cheapest pair to top of their respective stacks and pushes from b to a
 */

// TODO needs checking

void	push_cheapest(t_stk **a, t_stk **b, t_friends *t_arr, int i)
{
	int	a_c;
	int	b_c;

	a_c = t_arr[i].a_cost;
	b_c = t_arr[i].b_cost;
	if ((a_c >= 0 && b_c >= 0) || (a_c <= 0 && b_c <= 0))
		same_sign(a, b, a_c, b_c);
	else
		diff_sign(a, b, a_c, b_c);
	stk_mod(op_p, a, b, 'a');
}
