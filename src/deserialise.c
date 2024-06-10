/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:03:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 15:09:29 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "../libft/include/libft.h"

/*
 * Edited atoi to account for "-" returning 0 and INT_MIN/INT_MAX
 * atoi instead edits a int ptr to return the result to leave ints free for
 * errors.
 */

int	ft_atoi_ps(const char *nptr, long *output)
{
	int	neg;

	neg = 1;
	*output = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		*output = (*output * 10) + (*nptr - '0');
		nptr++;
	}
	*output *= neg;
    if ((neg == -1 && *output == 0) || *output < INT_MIN || INT_MAX < *output)
        return (-1);
    else
        return (0);
}

/* 
 TODO error handling, free stack
 TODO atoi returning 0 for letters.
 * Takes input from the command line and deserialises into linked list.
 * Works for both a list of args and a single string
 */

t_stack *parse_input(int ac, char **av)
{
    t_stack *head;
    int list_len;

    head = NULL;
    if (ac == 1)
        return (printf("error: no arguments\n"), NULL); // ! error
    else if(ac == 2)
    {
        av = ft_split(av[1], ' ');
        list_len = 0;
        while (av[list_len] != NULL)
            list_len++;
        head =format_list(list_len, av, 0);
    }
    else
        head =format_list(ac, av, 1);
    if (is_duplicate(head))
    {
        free_stk(head);
        return (printf("error duplicate\n"), NULL);
    }
    return head;
}

/*
 * 
 */

/* t_stack *format_string(char *str)
{
    t_stack *head;
    t_stack *node;
    int list_len;
    int i;
    long nbr;
    char **ops_list;

    head = NULL;
    ops_list = ft_split(str, ' ');
    list_len = 0;
    i = 0;
    while (ops_list[i++] != NULL)
        list_len++;
    i = 0;
    while (i < list_len)
    {
        nbr = ft_atoi_ps(ops_list[i++]);
        printf("%ld nbr\n", nbr);
        if (nbr < INT_MIN || INT_MAX < nbr)
        {
            free_stk(head);
            return (printf("error: number too big or small\n"), NULL);
        }
        node = ft_stknew(nbr);
        ft_stkadd_back(&head, node);
    }
    return head;
} */

t_stack *format_list(int ac, char **av, int start)
{
    t_stack *node;
    t_stack *head;
    long nbr;
    
    head = NULL;
    while (start < ac)
    {
        if (ft_atoi_ps(av[start++], &nbr) == -1)
        {
            free_stk(head);
            return (printf("error: invalid entry\n"), NULL);
        }
        node = ft_stknew(nbr);
        ft_stkadd_back(&head, node);
    }
    return head;
}
