/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:02:26 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/12 13:14:57 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stk **stk);
void	reverse_rotate(t_stk **stk);

/*
 * Operation rotate. Shifts all elements in head_a up by one.
 * First element becomes last.
 */

void	op_r(t_stk **a, t_stk **b, char c)
{
	if (c == 'a')
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (c == 'b')
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (c == 'r')
	{
		rotate(a);
		rotate(b);
		ft_putstr_fd("rr\n", 1);
	}
}

/*
 * Operation reverse rotate. Shifts all elements in head_a up by one.
 * Last element becomes first.
 */

void	op_rr(t_stk **a, t_stk **b, char c)
{
	if (c == 'a')
	{
		reverse_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (c == 'b')
	{
		reverse_rotate(b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (c == 'r')
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_putstr_fd("rrr\n", 1);
	}
}

/*
 * Function prototype for operation function pointers
 */

void	stk_mod(void (*mod)(t_stk **, t_stk **, char c), t_stk **a, t_stk **b,
		char c)
{
	return (mod(a, b, c));
}

void	reverse_rotate(t_stk **stk)
{
	t_stk	*first;
	t_stk	*penult;
	t_stk	*last;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	first = *stk;
	penult = first;
	while (penult->next->next != NULL)
		penult = penult->next;
	last = penult->next;
	last->next = first;
	penult->next = NULL;
	*stk = last;
}

void	rotate(t_stk **stk)
{
	t_stk	*curr;
	t_stk	*last;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;

	curr = *stk;
	last = stk_last(*stk);
	last->next = *stk;
	*stk = (*stk)->next;
	curr->next = NULL;
}
