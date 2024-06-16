/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:16:35 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/16 15:22:47 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_swap_both(t_stk **a, t_stk **b);
static void	rotate_both(t_stk **a, t_stk **b);
static void	reverse_rotate_both(t_stk **a, t_stk **b);

/*
 * Compares incoming instructions against accepted instructions. Returns
 * Error if instruction is not recognised.
 * Actuates instructions on the two stacks.
 */

int	interpret_instruction(t_stk **a, t_stk **b, char *l)
{
	if (ft_strncmp(l, "sa\n", 4) == 0)
		top_swap(a);
	else if (ft_strncmp(l, "sb\n", 4) == 0)
		top_swap(b);
	else if (ft_strncmp(l, "ss\n", 4) == 0)
		top_swap_both(a, b);
	else if (ft_strncmp(l, "pa\n", 4) == 0)
		push(b, a);
	else if (ft_strncmp(l, "pb\n", 4) == 0)
		push(a, b);
	else if (ft_strncmp(l, "ra\n", 4) == 0)
		rotate(a);
	else if (ft_strncmp(l, "rb\n", 4) == 0)
		rotate(b);
	else if (ft_strncmp(l, "rs\n", 4) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(l, "rra\n", 5) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(l, "rrb\n", 5) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(l, "rrr\n", 5) == 0)
		reverse_rotate_both(a, b);
	else
		return (ft_putstr_fd("Error\n", 2), -1);
	return (0);
}

static void	top_swap_both(t_stk **a, t_stk **b)
{
	top_swap(a);
	top_swap(b);
}

static void	rotate_both(t_stk **a, t_stk **b)
{
	rotate(a);
	rotate(b);
}

static void	reverse_rotate_both(t_stk **a, t_stk **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
