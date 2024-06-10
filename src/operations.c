/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:06:21 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 11:18:15 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Operation swaps first two elements in 'head_a'. Does nothing if 0 or 1 nodes
 */

void	op_s(t_stack **head_a, t_stack **head_b)
{
	t_stack	*stk;
	int		temp;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return;
	(void)head_b;
	stk = *head_a;
	if (stk->next)
	{
		temp = stk->content;
		stk->content = stk->next->content;
		stk->next->content = temp;
	}
}

/*
 * Push first element from head_from to top of head_to
 */

void op_p(t_stack **head_from, t_stack **head_to)
{
	t_stack *temp;
	
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

void	op_r(t_stack **head_a, t_stack **head_b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return;
	(void)head_b;
	first = *head_a;
	second = first->next;
	last = ft_stklast(first);

	last->next = first;
	first->next = NULL;
	*head_a = second;
}

/*
 * Operation reverse rotate. Shifts all elements in head_a up by one.
 * Last element becomes first.
 */

void	op_rr(t_stack **head_a, t_stack **head_b)
{
	t_stack *first;
	t_stack *penult;
	t_stack *last;

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

void	stk_mod(void (*mod)(t_stack **, t_stack **), t_stack **head_a,
		t_stack **head_b)
{
	return (mod(head_a, head_b));
}
