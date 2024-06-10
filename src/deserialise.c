/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:03:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 23:14:30 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*format_list(int count, char **strings, int start);
static int	ft_atoi_ps(const char *nptr, long *output);
static int	is_int(long nbr);

/*
 * Takes input from the command line and deserialises into linked list.
 * Works for both a list of args and a single space delimited string.
 */

t_stack	*parse_input(int ac, char **av)
{
	t_stack	*head;
	int		list_len;

	head = NULL;
	if (ac == 1)
		return (NULL);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		list_len = 0;
		while (av[list_len] != NULL)
			list_len++;
		head = format_list(list_len, av, 0);
	}
	else
		head = format_list(ac, av, 1);
	if (is_duplicate(head))
	{
		free_stk(head);
		return (ft_putstr_fd("Error\n", 2), NULL);
	}
	return (head);
}

/*
 * Converts each string in av vector into int and appends to list.
 * Count from 'argc' must begin from one, otherwise from 0.
 */

static t_stack	*format_list(int count, char **strings, int start)
{
	t_stack	*node;
	t_stack	*head;
	long	nbr;

	head = NULL;
	while (start < count)
	{
		if (ft_atoi_ps(strings[start++], &nbr) == -1)
		{
			free_stk(head);
			return (ft_putstr_fd("Error\n", 2), NULL);
		}
		node = ft_stknew(nbr);
		ft_stkadd_back(&head, node);
		// ft_lstadd_back(&head, node);
	}
	return (head);
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
