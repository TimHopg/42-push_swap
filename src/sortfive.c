/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:48:58 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/14 23:18:59 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_three(t_stk **a, t_stk **b);
int		sort_four(t_stk **a, t_stk **b);
int		sort_five(t_stk **a, t_stk **b);

/*
 * When a stack has three nodes, this function sorts them into ascending order.
 * First it checks if they are already in order, then performs the necessary
 * operations to order them.
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
		stk_mod(op_s, a, b, 'a');
		return (2);
	}
	stk_mod(op_rr, a, b, 'a');
	return (1);
}

/*
 * Pushes the smallest element to b then uses sort_three to order and
 * pushes the first value back to a.
 */

int	sort_four(t_stk **a, t_stk **b)
{
	move_to_top(a, list_min(*a));
	if (is_ordered(a) == 1)
		return (1);
	stk_mod(op_p, a, b, 'b');
	sort_three(a, b);
	stk_mod(op_p, a, b, 'a');
	return (1);
}

/*
 * Same as sort_four.
 */

int	sort_five(t_stk **a, t_stk **b)
{
	move_to_top(a, list_min(*a));
	if (is_ordered(a) == 1)
		return (1);
	stk_mod(op_p, a, b, 'b');
	sort_four(a, b);
	stk_mod(op_p, a, b, 'a');
	return (1);
}

/*
 * Reduces size of stack a to five. If top of stack a is lower than the mean,
 * it is pushed to b, if it's not, stack a is rotated.
 */

void	reduce_to_five(t_stk **a, t_stk **b)
{
	int	stk_mean;

	while (list_len(*a) > 5)
	{
		stk_mean = list_mean(*a);
		if ((*a)->content < stk_mean)
			stk_mod(op_p, a, b, 'b');
		else
			stk_mod(op_r, a, b, 'a');
	}
}
