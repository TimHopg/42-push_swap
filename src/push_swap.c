/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/16 18:26:34 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO visualiser
 TODO check printf doesn't exist (list all symbols)
 TODO read subject thoroughly
 TODO check leaks at school. "1 2 3" "" 1 2 3, etc.
 TODO check what the checker does at school "" etc.
 TODO Norm
 * Arguments can be passed "1 2 3" or 1 2 3 but not a combination of the two
 * Have chosen to interpret -0 and +0 as valid.
 * Uses a best friend type algorithm but optimised to share operations.
 * This algorithm is operation cheap but comparison expensive.
 * "" and " " both return Error. This is what the checker does, whereas no
 * parameters returns the prompt.
 * Improvements:
 * - mean of list assumes evenly distributed numbers
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
		if (t_arr == NULL)
		{
			free_stk(*a);
			free_stk(*b);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
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

// ft_printf("Before\n");
// ft_print_stk(a, 'a');
// ft_printf("\n");

// ft_printf("\n");
// ft_printf("After\n");
// ft_print_stk(a, 'a');
