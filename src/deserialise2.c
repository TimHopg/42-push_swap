/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialise2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:12:57 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/17 14:34:15 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Takes vector 'av', creates new vector from the nth string in av of split
 * strings. Appends the int value of these strings to stack 'a'.
 */

int split_sort(char **av, t_stk **a, int n)
{
    char **new_v;
    int v_len;

	new_v = ft_split(av[n], ' ');
	if (new_v == NULL)
		return (free_stk(*a), -1);
	v_len = 0;
	while (new_v[v_len] != NULL)
		v_len++;
	if (format_list(v_len, new_v, 0, a) < 0)
		return (free_av(new_v), -1);
	free_av(new_v);
    return (0);
}
