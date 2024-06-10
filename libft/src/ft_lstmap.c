/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:44:12 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Iterates list 'lst' and applies function 'f' to the contents of each node.
A new list is created from the result.

*/

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*curr;

	new_lst = NULL;
	curr = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		curr = ft_lstnew(NULL);
		if (curr == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		curr->content = (*f)(lst->content);
		ft_lstadd_back(&new_lst, curr);
		lst = lst->next;
	}
	return (new_lst);
}
