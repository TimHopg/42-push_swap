/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 11:22:29 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO should the stk be cyclical to avoid iterating over the whole stk?
 * or even doubly linked?
 TODO error reporting on channel 2
 TODO Count operations as they are being printed
*/

int	main(void)
{
	t_stack	*head_a = ft_stknew(1);
	t_stack	*node_a = ft_stknew(2);
	t_stack	*node_a2 = ft_stknew(3);
	t_stack	*node_a3 = ft_stknew(4);
	t_stack	*tail_a = ft_stknew(5);

	ft_stkadd_back(&head_a, node_a);
	ft_stkadd_back(&head_a, node_a2);
	ft_stkadd_back(&head_a, node_a3);
	ft_stkadd_back(&head_a, tail_a);

	// t_stack	*head_b = ft_stknew(INT_MIN);
	// t_stack	*node_b = ft_stknew(INT_MAX);
	// t_stack	*tail_b = ft_stknew(INT_MAX);
	
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
}

// int main(int ac, char **av)
// {
// 	parse_input(ac, av);
// }
