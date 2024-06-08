/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:54:26 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/08 13:54:41 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

// main
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstnew(int content);
void				ft_print_list(t_list *head, char c);

// utils
void				free_list(t_list *head);
t_list				*ft_lstlast(t_list *lst);
int 				is_duplicate(t_list *a);

// ops
void				op_s(t_list **head_a, t_list **head_b);
void				op_r(t_list **head_a, t_list **head_b);
void				op_rr(t_list **head_a, t_list **head_b);
void 				op_p(t_list **head_from, t_list **head_to);
void				lst_mod(void (*mod)(t_list **, t_list **), t_list
		**head_a, t_list **head_b);