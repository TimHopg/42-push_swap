/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:03:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/09 00:17:22 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 * Takes input from the command line and deserialises into linked list.
 * Works for both a list of args and a single string
 */

void parse_input(int ac, char **av)
{
    if (ac == 1)
        return; // ! error
    else if(ac == 2)
    {
        format_string(av[1]);
    }
    else
    {
        format_list(av);
    }
}

void format_string(char *str)
{
    
}