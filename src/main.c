/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 11:46:06 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO error reporting on channel 2
 TODO make sure if there are no arguments, nothing happens
 TODO Count operations as they are being printed
 TODO Error handling and freeing
 TODO remove char from print list
 TODO add printf, get_next_line, etc. to libft
 TODO ensure bonus doesn't relink
 TODO receives empty string
 TODO doubly linked list, ops receive char to determine output
 TODO INT_MIN & INT_MAX in string
 * Have chosen to interpret -0 and +0 as valid.
*/

int main(int ac, char **av)
{
	t_stack *head;

	head = NULL;
	head = parse_input(ac, av);

	if (head == NULL)
		return (-1);
	// printf("Before\n");
	ft_print_stk(head, 'a');
	printf("%d min\n", list_min(head));
	// printf("After\n");

}

/* int	main(void)
{
	// ft_stkadd_back(&head_b, node_b);
	// ft_stkadd_back(&head_b, tail_b);

	// printf("%d duplicates\n", is_duplicate(head_a));

	printf("Before\n");
	ft_print_stk(head_a, 'a');
	// printf("Before\n");
	// ft_print_stk(head_b, 'b');
	printf("\n");

	// t_stack *null_test = NULL;
	// stk_mod(op_s, &head_a, &null_test);
	// stk_mod(op_p, &head_a, &null_test);
	// stk_mod(op_r, &head_a, &null_test);
	// stk_mod(op_rr, &head_a, &null_test);
	
	printf("After\n");
	ft_print_stk(head_a, 'a');
	// printf("After\n");
	// ft_print_stk(head_b, 'b');
	printf("\n");
} */
