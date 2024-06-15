/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:57:27 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 18:47:13 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Prints list
 */

void	ft_print_stk(t_stk *head, char c)
{
	t_stk	*curr;
	int		i;

	curr = NULL;
	i = 1;
	curr = head;
	while (curr)
	{
		ft_printf("stk[%c] Node[%d]: %d\n", c, i++, curr->content);
		curr = curr->next;
	}
}

/*
 * Creates (and allocates memory) for new node with content data value
 */

t_stk	*ft_stknew(int content)
{
	t_stk	*new_node;

	new_node = malloc(sizeof(t_stk));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
 * Returns last node in stk
 */

t_stk	*stk_last(t_stk *stk)
{
	t_stk	*node;

	if (stk == NULL)
		return (NULL);
	node = stk;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

/*
 * Appends node 'new' to stk 'stk'
 */

void	ft_stkadd_back(t_stk **stk, t_stk *new)
{
	t_stk	*curr;

	if (stk == NULL || new == NULL)
		return ;
	curr = *stk;
	if (*stk == NULL)
		*stk = new;
	else
		stk_last(curr)->next = new;
}

/*
 * Frees all nodes in stk
 */

void	free_stk(t_stk *head)
{
	t_stk	*current;
	t_stk	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
