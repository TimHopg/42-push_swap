/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:48:58 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/12 16:36:48 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stk **a, t_stk **b);
int	sort_four(t_stk **a, t_stk **b);
int	sort_five(t_stk **a, t_stk **b);

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
		stk_mod(op_s, a, b, 'a');
		return (2);
	}
	stk_mod(op_rr, a, b, 'a');
	return (1);
}

int	sort_four(t_stk **a, t_stk **b)
{
    // smallest_to_top(a);
	move_to_top(a, list_min(*a));
    stk_mod(op_p, a, b, 'b');
    sort_three(a, b);
    stk_mod(op_p, a, b, 'a');
    return (1);
}

int	sort_five(t_stk **a, t_stk **b)
{
    // smallest_to_top(a);
	move_to_top(a, list_min(*a));
    stk_mod(op_p, a, b, 'b');
    sort_four(a, b);
    stk_mod(op_p, a, b, 'a');
    return (1);
}
