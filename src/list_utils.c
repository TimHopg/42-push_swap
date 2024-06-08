/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:57:27 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/08 22:25:30 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Prints list
 */

void	ft_print_list(t_list *head, char c)
{
	t_list	*curr;
	int		i;

	curr = NULL;
	i = 1;
	curr = head;
	while (curr)
	{
		printf("List[%c] Node[%d]: %d\n", c, i++, curr->content);
		curr = curr->next;
	}
}

/*
 * Creates (and allocates memory) for new node with content data value
 */

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
 * Returns last node in list
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

/*
 * Appends node 'new' to list 'lst'
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (lst == NULL || new == NULL)
		return ;
	curr = *lst;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(curr)->next = new;
}

/*
 * Frees all nodes in list
 */

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
