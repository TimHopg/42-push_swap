/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/12 00:27:47 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
 * Have chosen to interpret -0 and +0 as valid.
*/

int main(int ac, char **av)
{
	t_stk *a;
	t_stk *b;
	// t_stk *b_node;
	// t_stk *b_tail;

	a = NULL;
	b = NULL;
	// b = ft_stknew(7);
	// b_node = ft_stknew(8);
	// b_tail = ft_stknew(9);
	// ft_stkadd_back(&b, b_node);
	// ft_stkadd_back(&b, b_tail);

	if (parse_input(ac, av, &a) < 0)
		return (-1);

	printf("Before\n");
	ft_print_stk(a, 'a');
	// printf("\n");
	// ft_print_stk(b, 'b');
	// printf("\n");

	// stk_mod(op_s, &a, &b, 'b');
	// stk_mod(op_p, &a, &b, 'b');
	// stk_mod(op_r, &a, &b, 'r');
	// stk_mod(op_rr, &a, &b, 'r');
	// sort_three(&a, &b);
	
	printf("%d\n", sort_three(&a, &b));
	printf("After\n");
	ft_print_stk(a, 'a');
	// printf("\n");
	// ft_print_stk(b, 'b');

	// free_stk(a);
	// free_stk(b);
}
