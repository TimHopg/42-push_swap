/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:18:11 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/12 15:52:14 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stk **head);

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

int smallest_to_top(t_stk **a)
{
	int target;
	int index;

	if (*a == NULL)
		return (-1);
	target = list_min(*a);
	index = find_node(*a, target);
	if (index == 1)
		return (1);
	if (index < (list_len(*a) / 2))
	{
		while (find_node(*a, target) != 1)
			stk_mod(op_r, a, a, 'a');
		return (1);
	}
	while (find_node(*a, target) != 1)
		stk_mod(op_rr, a, a, 'a');
	return (1);
}
