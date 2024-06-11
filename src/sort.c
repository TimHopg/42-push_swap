/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:18:11 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/12 00:30:24 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stk **head);

/*
 * When a stack has three nodes, this function sorts them into ascending order.
 * First it checks if they are already in order,
 */

int	sort_three(t_stk **a, t_stk **b)
{
	if (is_ordered(a))
		return (0);
	if ((*a)->content < (stk_last(*a))->content)
	{
		stk_mod(op_s, a, b, 'a');
		if (is_ordered(a))
			return (1);
		stk_mod(op_r, a, b, 'a');
		return (2);
	}
	if ((*a)->content > (*a)->next->content)
	{
		stk_mod(op_r, a, b, 'a');
		if (is_ordered(a))
			return (1);
		stk_mod(op_r, a, b, 'a');
		return (2);
	}
	stk_mod(op_rr, a, b, 'a');
	return (1);
}

/*
 * Checks if nodes in list are ordered
 */

int	is_ordered(t_stk **a)
{
	t_stk *curr;

	curr = *a;
	if (*a == NULL || (*a)->next == NULL)
		return (1);
	while (curr->next)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}