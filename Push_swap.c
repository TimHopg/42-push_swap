/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/06 17:55:56 by thopgood         ###   ########.fr       */
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

void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				free_list(t_list *head);
t_list				*lst_newnode(int value);
void				ft_print_list(t_list *head, char c);

void op_s(t_list **head_a, t_list **head_b)
{
	t_list *list;
	void *temp;

	(void)head_b;
	list = *head_a;
	if (list->next)
	{
		temp = list->content;
		list->content = list->next->content;
		list->next->content = temp;
	}
}

void op_r(t_list **head_a, t_list **head_b)
{
	
}

void lst_mod(void (*mod)(t_list **, t_list **), t_list **head_a, t_list ** head_b)
{
	return (mod(head_a, head_b));
}

int	main(void)
{
	t_list	*head_a;
	t_list	*node_a;
	t_list	*tail_a;

	t_list	*head_b;
	t_list	*node_b;
	t_list	*tail_b;

	head_a = lst_newnode(1);
	node_a = lst_newnode(2);
	tail_a = lst_newnode(3);
	ft_lstadd_back(&head_a, node_a);
	ft_lstadd_back(&head_a, tail_a);

	head_b = lst_newnode(7);
	node_b = lst_newnode(8);
	tail_b = lst_newnode(9);
	ft_lstadd_back(&head_b, node_b);
	ft_lstadd_back(&head_b, tail_b);

	printf("Before\n");
	ft_print_list(head_a, 'a');
	printf("After\n");
	lst_mod(op_s, &head_a, &head_b);
	ft_print_list(head_a, 'a');
	printf("\n");

	printf("Before\n");
	ft_print_list(head_b, 'b');
	printf("After\n");
	lst_mod(op_s, &head_b, &head_b);
	ft_print_list(head_b, 'b');

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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curr;

	if (lst == NULL || f == NULL)
		return ;
	curr = lst;
	while (curr != NULL)
	{
		(*f)(curr->content);
		curr = curr->next;
	}
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
