/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 18:48:22 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO error reporting on channel 2
 TODO Count operations as they are being printed
 TODO Error handling and freeing
 * Have chosen to interpret -0 and +0 as valid.
*/

/* int	main(void)
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
} */

int main(int ac, char **av)
{
	t_stack *head;
	// long nbr;
	// int temp;

	// temp = ft_atoi_ps("-", &nbr);
	// printf("%d temp\n", temp);
	// printf("%ld temp\n", nbr);

	// (void)ac;
	// (void)av;
	// printf("%d ft_atoi_ps(\"-\")\n", atoi("-"));
	head = NULL;
	head = parse_input(ac, av);
	ft_print_stk(head, 'a');
}
