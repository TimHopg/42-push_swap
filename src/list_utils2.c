/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:55:36 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 18:48:30 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Returns min data value from list.
 */

int	list_min(t_stk *head)
{
	t_stk	*curr;
	int		min;

	curr = head;
	min = curr->content;
	while (curr)
	{
		if (curr->content < min)
			min = curr->content;
		curr = curr->next;
	}
	return (min);
}

/*
 * Returns length of list
 */

int	list_len(t_stk *stk)
{
	int	len;

	len = 0;
	if (!stk)
		return (len);
	while (stk)
	{
		len += 1;
		stk = stk->next;
	}
	return (len);
}

/*
 * Returns mean of data values from list.
 */

float	list_mean(t_stk *stk)
{
	float	f;
	int		len;

	f = 0;
	if (stk == NULL)
		return (f);
	len = list_len(stk);
	while (stk)
	{
		f += stk->content;
		stk = stk->next;
	}
	return (f / len);
}

/*
 * Find node in list and return nth node number. Index begins at 1.
 * Returns 0 if not found.
 */

int	find_node(t_stk *a, int x)
{
	int	n;

	n = 0;
	if (a == NULL)
		return (0);
	while (a)
	{
		n++;
		if (a->content == x)
			return (n);
		a = a->next;
	}
	return (0);
}

/*
 * Frees char **
 */

void	free_av(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
