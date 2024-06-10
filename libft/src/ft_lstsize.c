/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:45:41 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Iterates and returns count of list 'lst' size.

*/

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_size;
	t_list	*node;

	lst_size = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		++lst_size;
	}
	return (lst_size);
}
