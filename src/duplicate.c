/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:56:14 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 11:16:14 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Checks list for duplicate data in content. Hash table would be more efficient
 */

int is_duplicate(t_stack *stk)
{
	t_stack	*curr;

	while (stk)
	{
		curr = stk->next;
		while (curr)
		{
			if (stk->content == curr->content)
				return (1);
			curr = curr->next;
		}
		stk = stk->next;
	}
	return (0);
}