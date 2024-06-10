/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:54:26 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 18:50:46 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

// main
void				ft_stkadd_back(t_stack **stk, t_stack *new);
t_stack				*ft_stknew(int content);
void				ft_print_stk(t_stack *head, char c);

// utils
void				free_stk(t_stack *head);
t_stack				*ft_stklast(t_stack *stk);
int					is_duplicate(t_stack *a);

// ops
void				op_s(t_stack **head_a, t_stack **head_b);
void				op_p(t_stack **head_from, t_stack **head_to);
void				op_r(t_stack **head_a, t_stack **head_b);
void				op_rr(t_stack **head_a, t_stack **head_b);
void				stk_mod(void (*mod)(t_stack **, t_stack **), t_stack **head_a,
						t_stack **head_b);
// deserialise
t_stack 			*parse_input(int ac, char **av);

#endif