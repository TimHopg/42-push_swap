/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:06:21 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/08 17:24:17 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Operation swaps first two elements in 'head_a'. Does nothing if 0 or 1 nodes
 */

void	op_s(t_list **head_a, t_list **head_b)
{
	t_list	*list;
	int		temp;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return;
	(void)head_b;
	list = *head_a;
	if (list->next)
	{
		temp = list->content;
		list->content = list->next->content;
		list->next->content = temp;
	}
}

/*
 * Push first element from head_from to top of head_to
 */

void op_p(t_list **head_from, t_list **head_to)
{
	t_list *temp;
	
	if (*head_from == NULL || (head_to == NULL))
		return;
	temp = (*head_from)->next;
	(*head_from)->next = *head_to;
	*head_to = *head_from;
	*head_from = temp;
}

/*
 * Operation rotate. Shifts all elements in head_a up by one.
 * First element becomes last.
 */

void	op_r(t_list **head_a, t_list **head_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return;
	(void)head_b;
	first = *head_a;
	second = first->next;
	last = ft_lstlast(first);

	last->next = first;
	first->next = NULL;
	*head_a = second;
}

/*
 * Operation reverse rotate. Shifts all elements in head_a up by one.
 * Last element becomes first.
 */

void	op_rr(t_list **head_a, t_list **head_b)
{
	t_list *first;
	t_list *penult;
	t_list *last;

	(void)head_b;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return;
	first = *head_a;
	penult = first;
	while (penult->next->next != NULL)
		penult = penult->next;
	last = penult->next;
	last->next = first;
	penult->next = NULL;
	*head_a = last;
}

/*
 * Function prototype for operation function pointers
 */

void	lst_mod(void (*mod)(t_list **, t_list **), t_list **head_a,
		t_list **head_b)
{
	return (mod(head_a, head_b));
}
