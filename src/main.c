/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/08 23:02:31 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO should the list be cyclical to avoid iterating over the whole list?
 * or even doubly linked?
 TODO error reporting on channel 2
 TODO Count operations as they are being printed
*/

int	main(void)
{
	t_list	*head_a = ft_lstnew(1);
	t_list	*node_a = ft_lstnew(2);
	t_list	*node_a2 = ft_lstnew(3);
	t_list	*node_a3 = ft_lstnew(4);
	t_list	*tail_a = ft_lstnew(5);

	ft_lstadd_back(&head_a, node_a);
	ft_lstadd_back(&head_a, node_a2);
	ft_lstadd_back(&head_a, node_a3);
	ft_lstadd_back(&head_a, tail_a);

	// t_list	*head_b = ft_lstnew(INT_MIN);
	// t_list	*node_b = ft_lstnew(INT_MAX);
	// t_list	*tail_b = ft_lstnew(INT_MAX);
	
	// ft_lstadd_back(&head_b, node_b);
	// ft_lstadd_back(&head_b, tail_b);

	// printf("%d duplicates\n", is_duplicate(head_a));

	printf("Before\n");
	ft_print_list(head_a, 'a');
	// printf("Before\n");
	// ft_print_list(head_b, 'b');
	printf("\n");

	t_list *null_test = NULL;
	// lst_mod(op_s, &head_a, &null_test);
	// lst_mod(op_p, &head_a, &null_test);
	// lst_mod(op_r, &head_a, &null_test);
	// lst_mod(op_rr, &head_a, &null_test);
	
	printf("After\n");
	ft_print_list(head_a, 'a');
	// printf("After\n");
	// ft_print_list(head_b, 'b');
	printf("\n");
}
