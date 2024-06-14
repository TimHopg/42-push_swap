/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 20:59:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO remove all printfs
 TODO could add count each time operations are called, they could return
	TODO number of operations. count +=
 TODO make sure if there are no arguments, nothing happens
 TODO Count operations as they are being printed
 TODO Error handling and freeing
 TODO remove char from print list
 TODO add printf, get_next_line, etc. to libft
 TODO ensure bonus doesn't relink
 TODO receives empty string
 TODO INT_MIN & INT_MAX in string
 TODO could mean have to be a float. Check accuracy too
 TODO best friend can be optimised to share rotations
 * Have chosen to interpret -0 and +0 as valid.
 * This algorithm is operation cheap but comparison expensive.
 ? What so best friends are shared. What if the bigger of the two is
 	? popped first??? Are the best friends calculated after each pop?

 TODO working out number of moves to the top, return a positive or negative number.
 	TODO this way a reverse rotation can be offset against a rotation to determine
	TODO true cheapest choice.
 TODO - might need a pointer to the friends struct?
*/

/*
 * Prepares stacks for cheapest push from b to when both moves to get a and b to
 * the top are positive or both moves are negative.
 */

void same_sign(t_stk **a, t_stk ** b, int a_c, int b_c)
{
	int n;
	void (*op_func)(t_stk **, t_stk **, char);

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

void diff_sign(t_stk **a, t_stk ** b, int a_c, int b_c)
{
	int n;

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

void push_cheapest(t_stk **a, t_stk ** b, t_friends *t_arr, int i)
{
	int a_c = t_arr[i].a_cost;
	int b_c = t_arr[i].b_cost;

	if ((a_c >= 0 && b_c >= 0) || (a_c <= 0 && b_c <= 0))
		same_sign(a, b, a_c, b_c);
	else
		diff_sign(a, b, a_c, b_c);
	stk_mod(op_p, a, b, 'a');
}

/*
 * Finds cheapest total cost 'tot_cost' from stack b and each node's best friend
 */

void find_cheapest(t_friends *t_arr, int b_len, t_stk **a, t_stk **b)
{
	int i;
	int lowest_cost;
	int cheap_index;

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

/*
 * Rotates stack a until top number is lowest.
 ! Optimise, if min is lower than halfway
 */

void rotate_a(t_stk **a)
{
	int min;

	min = list_min(*a);
	while ((*a)->content != min)
		stk_mod(op_r, a, a, 'a');
}

/*
 * Calls each function to implement algorithm
 */

void best_friend(t_stk **a, t_stk **b)
{
	t_friends *t_arr;
	int b_len;

	reduce_to_five(a, b);
	sort_five(a, b);
	while (list_len(*b) > 0)
	{
		b_len = list_len(*b);
		t_arr = build_f_array(a, b);
		find_cheapest(t_arr, b_len, a, b);
	}
	rotate_a(a);
	free_stk(*b);
}

/*
 * Handles stacks < 5 in length and stacks already ordered.
 * Then calls algorithm.
 */

static int preprocessing(t_stk **a)
{
	t_stk *b;
	int stk_len;

	b = NULL;
	stk_len = list_len(*a);
	if(is_ordered(a))
		return (1);
	if (stk_len == 2)
		return (stk_mod(op_s, a, &b, 'a'), 1);
	if (stk_len == 3)
		return (sort_three(a, &b));
	if (stk_len == 4)
		return (sort_four(a, &b));
	if (stk_len == 5)
		return (sort_five(a, &b));
	best_friend(a, &b);
	return (0);
}

int main(int ac, char **av)
{
	t_stk *a;

	a = NULL;
	if (parse_input(ac, av, &a) < 0)
		return (-1);
	
	// printf("Before\n");
	// ft_print_stk(a, 'a');
	// printf("\n");

	preprocessing(&a);

	// printf("\n");
	// printf("After\n");
	// ft_print_stk(a, 'a');

	free_stk(a);
	return (0);
}
