/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/12 17:51:46 by thopgood         ###   ########.fr       */
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
*/


// int smallest_to_top(t_stk **a)
// {
// 	int target;
// 	int index;

// 	if (*a == NULL)
// 		return (-1);
// 	target = list_min(*a);
// 	index = find_node(*a, target);
// 	if (index == 1)
// 		return (1);
// 	if (index < (list_len(*a) / 2))
// 	{
// 		while (find_node(*a, target) != 1)
// 			stk_mod(op_r, a, a, 'a');
// 		return (1);
// 	}
// 	while (find_node(*a, target) != 1)
// 		stk_mod(op_rr, a, a, 'a');
// 	return (1);
// }

int determine_friend(t_stk *a, int data)
{
	t_stk *curr;
	int friend;

	curr = a;
	friend = curr->data;
	while (curr)
	{
		curr->data
	}
}

/*
 * Function expects 'data' to be found in list. Returns how many moves it
 * would take to move 'data' node to top. negative value is rr and positive
 * value is r.
 */

int to_top_cost(t_stk *stk, int data)
{
	int index;
	int len;

	index = find_node(stk, data);
	len = list_len(stk);
	if (index - 1 > (len / 2))
		return (index - len - 1);
	return (index - 1);
}

void reduce_to_five(t_stk **a, t_stk **b)
{
	int stk_mean;

	while (list_len(*a) > 5)
	{
		stk_mean = list_mean(*a);
		if ((*a)->content < stk_mean)
			stk_mod(op_p, a, b, 'b');
		else
			stk_mod(op_r, a, b, 'a');
	}
}

void best_friend(t_stk **a, t_stk **b)
{
	reduce_to_five(a, b);
	sort_five(a, b);
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
