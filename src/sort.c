/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:18:11 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/17 15:50:15 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_ordered(t_stk **head);

/*
 * Checks if nodes in list are ordered
 */

int	is_ordered(t_stk **a)
{
	t_stk	*curr;

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

/*
 * Moves selected node to top of list.
 */

int	move_to_top(t_stk **stk, int data)
{
	int	index;

	if (*stk == NULL)
		return (-1);
	index = find_node(*stk, data);
	if (index == 1)
		return (1);
	if (index - 1 <= (list_len(*stk) / 2))
	{
		while (find_node(*stk, data) != 1)
			stk_mod(op_r, stk, stk, 'a');
		return (1);
	}
	while (find_node(*stk, data) != 1)
		stk_mod(op_rr, stk, stk, 'a');
	return (0);
}

/*
 * Function expects 'data' to be found in list. Returns how many moves it
 * would take to move 'data' node to top. negative value is rr and positive
 * value is r.
 */

int	to_top_cost(t_stk *stk, int data)
{
	int	index;
	int	len;

	index = find_node(stk, data);
	len = list_len(stk);
	if (index - 1 > (len / 2))
		return (index - len - 1);
	return (index - 1);
}

/*
 * Determines the best friend in stack a of 'data' from stack b.
 * To optimise: since stk a is sorted, loop could stop when potential
 * friends are getting worse.
 */

int	determine_friend(t_stk *a, int data)
{
	t_stk	*curr;
	int		friend;

	curr = a;
	while (curr->content < data)
		curr = curr->next;
	friend = curr->content;
	while (curr)
	{
		if (curr->content < friend && ((curr->content - data) > 0))
			friend = curr->content;
		curr = curr->next;
	}
	return (friend);
}

/*
 * allocates t_friends array of length (usually length of stack b)
 */

t_friends	*allocate_f_array(int len)
{
	t_friends	*f_arr;

	f_arr = malloc(sizeof(t_friends) * len);
	if (f_arr == NULL)
		return (NULL);
	return (f_arr);
}
