/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:54:26 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 18:41:53 by thopgood         ###   ########.fr       */
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
}					t_stk;

// main
void				ft_stkadd_back(t_stk **stk, t_stk *new);
t_stk				*ft_stknew(int content);
void				ft_print_stk(t_stk *head, char c);

// utils
void				free_stk(t_stk *head);
t_stk				*stk_last(t_stk *stk);
int					list_min(t_stk *head);
int					list_max(t_stk *head);

// ops
void				op_s(t_stk **a, t_stk **b, char c);
void				op_p(t_stk **from, t_stk **to, char c);
void				op_r(t_stk **a, t_stk **b, char c);
void				op_rr(t_stk **a, t_stk **b, char c);
void				stk_mod(void (*mod)(t_stk **, t_stk **, char c), t_stk **a,
						t_stk **b, char c);
// deserialise
int					parse_input(int ac, char **av, t_stk **head);
int					is_duplicate(t_stk *a);

// sort
int					last_three(t_stk **head_a, t_stk **head_b);

#endif