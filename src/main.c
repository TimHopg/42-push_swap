/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 16:48:17 by thopgood         ###   ########.fr       */
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

// void same_sign(t_stk **a, t_stk ** b, t_friends *t_arr, int i)
// {
	
// }

void push_cheapest(t_stk **a, t_stk ** b, t_friends *t_arr, int i)
{
	int n;
	// char c;
	int a_c = t_arr[i].a_cost;
	int b_c = t_arr[i].b_cost;
	void (*op_func)(t_stk **, t_stk **, char);

	n = 0;
	printf("%d a_c\n", a_c);
	printf("%d b_c\n", b_c);
	op_func = op_r;
	if ((a_c >= 0 && b_c >= 0) || (a_c <= 0 && b_c <= 0))
	{
		if (a_c <= 0 && b_c <= 0)
			op_func = op_rr;
		if (a_c > b_c)
			n = b_c;
		else
			n = a_c;
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
	else
	{
		if (a_c > 0)
	}
	stk_mod(op_p, a, b, 'a');
}

void find_cheapest(t_friends *t_arr, int b_len, t_stk **a, t_stk **b)
{
	int i;
	int lowest_cost;
	int cheap_index;

	(void)a;
	(void)b;
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
	printf("%d cheapest index at cost of -> %d\n", cheap_index, lowest_cost);
	push_cheapest(a, b, t_arr, cheap_index);
	// free(t_arr);
}

void best_friend(t_stk **a, t_stk **b)
{
	t_friends *t_arr;
	int b_len;

	reduce_to_five(a, b);
	sort_five(a, b);
	b_len = list_len(*b);
	// while (list_len(*b) > 0)
	// {}
	t_arr = build_f_array(a, b);
	find_cheapest(t_arr, b_len, a, b);
	ft_print_stk(*b, 'b');
	// printf("%d friend\n", determine_friend(*a, (*b)->next->next->content));
	printf("\n");
}

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
	
	printf("Before\n");
	ft_print_stk(a, 'a');

	printf("\n");
	// printf("%d cost\n", to_top_cost(a, 5));
	// move_to_top(&a, 5);
	preprocessing(&a);
	printf("\n");

	printf("After\n");
	ft_print_stk(a, 'a');

	printf("%d tot cost\n", tot_cost(-3, 0));

	// best_friend(&a);
	
	// ft_print_stk(b, 'b');
	// printf("\n");

	// stk_mod(op_s, &a, &b, 'b');
	// stk_mod(op_p, &a, &b, 'b');
	// stk_mod(op_r, &a, &b, 'r');
	// stk_mod(op_rr, &a, &b, 'r');
	// sort_three(&a, &b);
	
	// printf("%d\n", sort_three(&a, &b));
	// printf("After\n");
	// ft_print_stk(a, 'a');
	// printf("\n");
	// ft_print_stk(b, 'b');

	// free_stk(a);
	// free_stk(b);
	return (0);
}
