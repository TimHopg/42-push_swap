/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:23:06 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/08 17:13:18 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 TODO should the list be cyclical to avoid iterating over the whole list?
 * or even doubly linked?
*/

// main
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
void				ft_print_list(t_list *head, char c);

// utils
void				free_list(t_list *head);
t_list				*ft_lstlast(t_list *lst);
// void				*ft_calloc(size_t nitems, size_t size);
// void				*ft_memset(void *b, int c, size_t len);
int 				is_duplicate(t_list *a);

// ops
void				op_s(t_list **head_a, t_list **head_b);
void				op_r(t_list **head_a, t_list **head_b);
void				op_rr(t_list **head_a, t_list **head_b);
void 				op_p(t_list **head_from, t_list **head_to);
void				lst_mod(void (*mod)(t_list **, t_list **), t_list
		**head_a, t_list **head_b);

// int is_duplicate(t_list *a)
// {
// 	int index;
//     int *seen;
	
// 	seen = ft_calloc(INT_MAX - INT_MIN + 1, sizeof(int));
//     if (!seen)
//         return -1;
//     while (a)
//     {
//         index = *(int *)a->content - INT_MIN;
//         if (seen[index])
//             return free(seen), 1;
//         seen[index] = 1;
//         a = a->next;
//     }
//     free(seen);
//     return 0;
// }

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

int	main(void)
{
	// t_list	*head_a = ft_lstnew(1);
	t_list *null_test = NULL;
	// t_list	*node_a = ft_lstnew(2);
	// t_list	*node_a2 = ft_lstnew(3);
	// t_list	*node_a3 = ft_lstnew(4);
	// t_list	*tail_a = ft_lstnew(5);

	// ft_lstadd_back(&head_a, node_a);
	// ft_lstadd_back(&head_a, node_a2);
	// ft_lstadd_back(&head_a, node_a3);
	// ft_lstadd_back(&head_a, tail_a);

	// t_list	*head_b = ft_lstnew(INT_MIN);
	// t_list	*node_b = ft_lstnew(INT_MAX);
	// t_list	*tail_b = ft_lstnew(INT_MAX);
	
	// ft_lstadd_back(&head_b, node_b);
	// ft_lstadd_back(&head_b, tail_b);

	// printf("%d duplicates\n", is_duplicate(head_a));

	printf("Before\n");
	// ft_print_list(head_a, 'a');
	// printf("Before\n");
	// ft_print_list(head_b, 'b');
	printf("\n");

	lst_mod(op_s, &null_test, &null_test);
	
	printf("After\n");
	// ft_print_list(head_a, 'a');
	// printf("After\n");
	// ft_print_list(head_b, 'b');
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
		printf("List[%c] Node[%d]: %d\n", c, i++, curr->content);
		curr = curr->next;
	}
}

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
		free(current);
		current = next;
	}
}
