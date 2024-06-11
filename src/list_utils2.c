/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:55:36 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 23:35:29 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	list_max(t_stk *head)
{
	t_stk	*curr;
	int		max;

	curr = head;
	max = curr->content;
	while (curr)
	{
		if (curr->content > max)
			max = curr->content;
		curr = curr->next;
	}
	return (max);
}
