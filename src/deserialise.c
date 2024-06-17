/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:03:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/17 14:38:50 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_ps(const char *nptr, long *output);
static int	is_int(long nbr);
int			is_duplicate(t_stk *stk);

/*
 * Takes input from the command line and deserialises into linked list.
 * Works for both a list of args and a single space delimited string.
 */

int	parse_input(int ac, char **av, t_stk **head)
{
	int i;

	i = 1;
	if (ac == 1)
		return (-1);
	while (i <= ac - 1)
		if (split_sort(av, head, i++) < 0)
			return (-1);
	if (is_duplicate(*head) || *head == NULL)
		return (free_stk(*head), ft_putstr_fd("Error\n", 2), -1);
	return (0);
}

int	parse_input_ORIGINAL(int ac, char **av, t_stk **head)
{
	int	list_len;

	if (ac == 1)
		return (-1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (free_stk(*head), -1);
		list_len = 0;
		while (av[list_len] != NULL)
			list_len++;
		if (format_list(list_len, av, 0, head) < 0)
			return (free_av(av), -1);
		free_av(av);
	}
	else if (format_list(ac, av, 1, head) < 0)
		return (-1);
	if (is_duplicate(*head) || *head == NULL)
		return (free_stk(*head), ft_putstr_fd("Error\n", 2), -1);
	return (0);
}

/*
 * Converts each string in av vector into int and appends to list.
 * Count from 'argc' must begin from one, otherwise from 0.
 */

int	format_list(int count, char **strs, int start, t_stk **head)
{
	t_stk	*node;
	long	nbr;

	while (start < count)
	{
		if (ft_atoi_ps(strs[start++], &nbr) == -1)
			return (free_stk(*head), ft_putstr_fd("Error\n", 2), -1);
		node = ft_stknew(nbr);
		if (node == NULL)
		{
			free_stk(*head);
			exit(1);
		}
		ft_stkadd_back(head, node);
	}
	return (0);
}

int	format_list_ORIGINAL(int count, char **strs, int start, t_stk **head)
{
	t_stk	*node;
	long	nbr;

	while (start < count)
	{
		if (ft_atoi_ps(strs[start++], &nbr) == -1)
			return (free_stk(*head), ft_putstr_fd("Error\n", 2), -1);
		node = ft_stknew(nbr);
		if (node == NULL)
		{
			free_stk(*head);
			exit(1);
		}
		ft_stkadd_back(head, node);
	}
	return (0);
}

/*
 * Checks list for duplicate data in content. Hash table would be more efficient
 */

int	is_duplicate(t_stk *stk)
{
	t_stk	*curr;

	while (stk)
	{
		curr = stk->next;
		while (curr)
		{
			if (stk->content == curr->content)
				return (1);
			curr = curr->next;
		}
		stk = stk->next;
	}
	return (0);
}

static int	is_int(long nbr)
{
	return (INT_MIN <= nbr && nbr <= INT_MAX);
}

/*
 * Edited atoi to handle "-", < INT_MIN, > INT_MAX and non alpha input.
 * Function instead edits an int ptr to return the result to leave ints free
 * to handle errors.
 */

static int	ft_atoi_ps(const char *nptr, long *output)
{
	int	neg;

	neg = 1;
	*output = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			neg = -1;
	if (*nptr == '\0')
		return (-1);
	while (ft_isdigit(*nptr))
		*output = (*output * 10) + (*nptr++ - '0');
	*output *= neg;
	if (!is_int(*output) || *nptr != '\0')
		return (-1);
	else
		return (0);
}
