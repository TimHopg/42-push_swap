/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 23:22:40 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO Error handling and freeing
 TODO ft_printstk ft_printf
 TODO add printf, get_next_line, etc. to libft
 TODO ensure bonus doesn't relink
 * Have chosen to interpret -0 and +0 as valid.
 * Uses a best friend type algorithm but optimised to share operations.
 * This algorithm is operation cheap but comparison expensive.
*/

/*
 * Calls each function to implement algorithm
 */

static void	best_friend(t_stk **a, t_stk **b)
{
	t_friends	*t_arr;
	int			b_len;

	reduce_to_five(a, b);
	sort_five(a, b);
	while (list_len(*b) > 0)
	{
		b_len = list_len(*b);
		t_arr = build_f_array(a, b);
		find_cheapest(t_arr, b_len, a, b);
	}
	move_to_top(a, list_min(*a));
	free_stk(*b);
}

/*
 * Handles stacks < 5 in length and stacks already ordered.
 * Then calls algorithm.
 */

static int	preprocessing(t_stk **a)
{
	t_stk	*b;
	int		stk_len;

	b = NULL;
	stk_len = list_len(*a);
	if (is_ordered(a))
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

int	main(int ac, char **av)
{
	t_stk	*a;

	a = NULL;
	if (parse_input(ac, av, &a) < 0)
		return (-1);
	preprocessing(&a);
	free_stk(a);
	return (0);
}

// printf("Before\n");
// ft_print_stk(a, 'a');
// printf("\n");

// printf("\n");
// printf("After\n");
// ft_print_stk(a, 'a');
