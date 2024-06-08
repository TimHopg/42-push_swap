/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:56:14 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/08 19:01:13 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Checks list for duplicate data in content. Hash table would be more efficient
 */

int is_duplicate(t_list *lst)
{
	t_list	*curr;

	while (lst)
	{
		curr = lst->next;
		while (curr)
		{
			if (lst->content == curr->content)
				return (1);
			curr = curr->next;
		}
		lst = lst->next;
	}
	return (0);
}