/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:18:11 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 19:09:53 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_three_ordered(t_stk **head);

/*
 * When a stack has three nodes, this function sorts them into ascending order.
 * First it checks if they are already in order,
 */

int	last_three(t_stk **a, t_stk **b)
{
	(void)b;
    if ((*a)->content < (stk_last(*a))->content)
    
	if (is_three_ordered(a))
        return (1);
    return(0);
}

static int	is_three_ordered(t_stk **a)
{
	return ((list_min(*a) == (*a)->content
			&& list_max(*a) == (stk_last(*a))->content));
}