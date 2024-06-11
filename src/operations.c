/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:06:21 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 19:23:24 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Operation swaps first two elements in 'head_a'. Does nothing if 0 or 1 nodes
 */

void	op_s(t_stk **a, t_stk **b, char c)
{
	t_stk	*stk;
	int		temp;

	if (c == 'b')
		*a = *b;
	else if (c == 's')
		op_s(a, b, 'a');
	if (*a == NULL || (*a)->next == NULL)
		return ;
	stk = *a;
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

void	op_p(t_stk **from, t_stk **to, char c)
{
	t_stk	*temp;

	(void)c;
	if (*from == NULL || (to == NULL))
		return ;
	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
}

/*
 * Operation rotate. Shifts all elements in head_a up by one.
 * First element becomes last.
 */

void	op_r(t_stk **a, t_stk **b, char c)
{
	t_stk	*first;
	t_stk	*second;
	t_stk	*last;

	(void)c;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	(void)b;
	first = *a;
	second = first->next;
	last = stk_last(first);
	last->next = first;
	first->next = NULL;
	*a = second;
}

/*
 * Operation reverse rotate. Shifts all elements in head_a up by one.
 * Last element becomes first.
 */

void	op_rr(t_stk **a, t_stk **b, char c)
{
	t_stk	*first;
	t_stk	*penult;
	t_stk	*last;

	(void)b;
	(void)c;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	penult = first;
	while (penult->next->next != NULL)
		penult = penult->next;
	last = penult->next;
	last->next = first;
	penult->next = NULL;
	*a = last;
}

/*
 * Function prototype for operation function pointers
 */

void	stk_mod(void (*mod)(t_stk **, t_stk **, char c), t_stk **a, t_stk **b,
		char c)
{
	return (mod(a, b, c));
}
