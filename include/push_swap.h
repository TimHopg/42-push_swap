/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:54:26 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/16 14:23:23 by thopgood         ###   ########.fr       */
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

typedef struct s_friends
{
	int				a_data;
	int				b_data;
	int				a_cost;
	int				b_cost;
	int				tot_cost;
}					t_friends;

// main
void				ft_stkadd_back(t_stk **stk, t_stk *new);
t_stk				*ft_stknew(int content);
void				ft_print_stk(t_stk *head, char c);

// utils
void				free_stk(t_stk *head);
t_stk				*stk_last(t_stk *stk);
int					list_min(t_stk *head);
int					list_len(t_stk *stk);
float				list_mean(t_stk *stk);
int					find_node(t_stk *a, int x);
void				free_av(char **arr);

// ops
void				op_s(t_stk **a, t_stk **b, char c);
void				op_p(t_stk **a, t_stk **b, char c);
void				op_r(t_stk **a, t_stk **b, char c);
void				op_rr(t_stk **a, t_stk **b, char c);
void				stk_mod(void (*mod)(t_stk **, t_stk **, char c), t_stk **a,
						t_stk **b, char c);

// deserialise
int					parse_input(int ac, char **av, t_stk **head);
int					is_duplicate(t_stk *a);

// sort
int					sort_three(t_stk **head_a, t_stk **head_b);
int					sort_four(t_stk **a, t_stk **b);
int					sort_five(t_stk **a, t_stk **b);
void				reduce_to_five(t_stk **a, t_stk **b);
int					is_ordered(t_stk **head);
int					to_top_cost(t_stk *stk, int data);
int					move_to_top(t_stk **stk, int data);
t_friends			*allocate_f_array(int len);
int					determine_friend(t_stk *a, int data);
t_friends			*build_f_array(t_stk **a, t_stk **b);
int					tot_cost(int a, int b);
void				find_cheapest(t_friends *t_arr, int b_len, t_stk **a,
						t_stk **b);
void				push_cheapest(t_stk **a, t_stk **b, t_friends *t_arr,
						int i);

// checker
void				push(t_stk **from, t_stk **to);
int					interpret_instruction(t_stk **a, t_stk **b, char *l);
void				top_swap(t_stk **stack);
void				reverse_rotate(t_stk **stk);
void				rotate(t_stk **stk);

#endif
