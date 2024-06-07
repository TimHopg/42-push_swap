/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/07 09:48:52 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/*
 TODO should the list be cyclical to avoid iterating over the whole list?
 * or even doubly linked?
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// main
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(void *content);
t_list				*lst_newnode(int value);
void				ft_print_list(t_list *head, char c);

// utils
void				free_list(t_list *head);
t_list				*ft_lstlast(t_list *lst);

// ops
void				op_s(t_list **head_a, t_list **head_b);
void				op_r(t_list **head_a, t_list **head_b);
void				op_rr(t_list **head_a, t_list **head_b);
void 				op_p(t_list **head_from, t_list **head_to);
void				lst_mod(void (*mod)(t_list **, t_list **), t_list
		**head_a, t_list **head_b);

void	op_s(t_list **head_a, t_list **head_b)
{
	t_list	*list;
	void	*temp;

	(void)head_b;
	list = *head_a;
	if (list->next)
	{
		temp = list->content;
		list->content = list->next->content;
		list->next->content = temp;
	}
}

void	op_r(t_list **head_a, t_list **head_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return;

	(void)head_b;
	first = *head_a;
	second = first->next;
	last = ft_lstlast(first);

	last->next = first;
	first->next = NULL;
	*head_a = second;
}

void	op_rr(t_list **head_a, t_list **head_b)
{
	t_list *first;
	t_list *penult;
	t_list *last;

	(void)head_b;
	if (*head_a == NULL || (*head_a)->next == NULL)
		return;
	first = *head_a;
	penult = first;
	while (penult->next->next != NULL)
		penult = penult->next;
	last = penult->next;
	last->next = first;
	penult->next = NULL;
	*head_a = last;
}

void op_p(t_list **head_from, t_list **head_to)
{
	t_list *temp;
	
	temp = (*head_from)->next;
	(*head_from)->next = *head_to;
	*head_to = *head_from;
	*head_from = temp;
}

void	lst_mod(void (*mod)(t_list **, t_list **), t_list **head_a,
		t_list **head_b)
{
	return (mod(head_a, head_b));
}

int	main(void)
{
	t_list	*head_a;
	t_list	*node_a;
	t_list	*node_a2;
	t_list	*node_a3;
	t_list	*tail_a;

	t_list	*head_b;
	t_list	*node_b;
	t_list	*tail_b;

	head_a = lst_newnode(1);
	node_a = lst_newnode(2);
	node_a2 = lst_newnode(3);
	node_a3 = lst_newnode(4);
	tail_a = lst_newnode(5);
	ft_lstadd_back(&head_a, node_a);
	ft_lstadd_back(&head_a, node_a2);
	ft_lstadd_back(&head_a, node_a3);
	ft_lstadd_back(&head_a, tail_a);


	head_b = lst_newnode(7);
	node_b = lst_newnode(8);
	tail_b = lst_newnode(9);
	ft_lstadd_back(&head_b, node_b);
	ft_lstadd_back(&head_b, tail_b);

	printf("Before\n");
	ft_print_list(head_a, 'a');
	printf("Before\n");
	ft_print_list(head_b, 'b');
	printf("\n");

	lst_mod(op_p, &head_b, &head_a);
	
	printf("After\n");
	ft_print_list(head_a, 'a');
	printf("After\n");
	ft_print_list(head_b, 'b');
	printf("\n");
}

void	ft_print_list(t_list *head, char c)
{
	t_list	*curr;
	int		i;

	curr = NULL;
	i = 1;
	curr = head;
	while (curr)
	{
		printf("List[%c] Node[%d]: %d\n", c, i++, *(int *)curr->content);
		curr = curr->next;
	}
}

t_list	*lst_newnode(int value)
{
	t_list	*new_node;
	int		*content;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	content = malloc(sizeof(int));
	if (!content)
	{
		free(new_node);
		return (NULL);
	}
	*content = value;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

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

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->content = content;
	return (new_node);
}

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

void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}
