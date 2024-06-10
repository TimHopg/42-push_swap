/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:57:27 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 11:16:50 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Prints list
 */

void	ft_print_stk(t_stack *head, char c)
{
	t_stack	*curr;
	int		i;

	curr = NULL;
	i = 1;
	curr = head;
	while (curr)
	{
		printf("stk[%c] Node[%d]: %d\n", c, i++, curr->content);
		curr = curr->next;
	}
}

/*
 * Creates (and allocates memory) for new node with content data value
 */

t_stack	*ft_stknew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
 * Returns last node in stk
 */

t_stack	*ft_stklast(t_stack *stk)
{
	t_stack	*node;

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

void	ft_stkadd_back(t_stack **stk, t_stack *new)
{
	t_stack	*curr;

	if (stk == NULL || new == NULL)
		return ;
	curr = *stk;
	if (*stk == NULL)
		*stk = new;
	else
		ft_stklast(curr)->next = new;
}

/*
 * Frees all nodes in stk
 */

void	free_stk(t_stack *head)
{
	t_stack	*current;
	t_stack	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
