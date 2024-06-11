/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:06:21 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 23:35:25 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_swap(t_stk **stack);
void		push(t_stk **from, t_stk **to);

/*
 * Operation swaps first two elements in 'head_a'. Does nothing if 0 or 1
 * node(s)
 */

void	op_s(t_stk **a, t_stk **b, char c)
{
	if (c == 'a')
	{
		top_swap(a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (c == 'b')
	{
		top_swap(b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (c == 's')
	{
		top_swap(a);
		top_swap(b);
		ft_putstr_fd("ss\n", 1);
	}
}

/*
 * Push first element from head_from to top of head_to
 */

void	op_p(t_stk **a, t_stk **b, char c)
{
	if (c == 'a')
	{
		push(b, a);
		ft_putstr_fd("pa\n", 1);
	}
	else if (c == 'b')
	{
		push(a, b);
		ft_putstr_fd("pb\n", 1);
	}
}

static void	top_swap(t_stk **stack)
{
	t_stk	*stk;
	int		temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	stk = *stack;
	temp = stk->content;
	stk->content = stk->next->content;
	stk->next->content = temp;
}

void	push(t_stk **from, t_stk **to)
{
	t_stk	*temp;

	if (*from == NULL || (to == NULL))
		return ;
	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
}
