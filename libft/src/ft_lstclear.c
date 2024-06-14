/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:32:31 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:42:00 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Deletes and frees each node in a list 'lst' and sets the pointer to the list
	to NULL

*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (lst == NULL)
		return ;
	while (*lst != NULL && del != NULL)
	{
		curr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = curr;
	}
}
