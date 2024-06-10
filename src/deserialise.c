/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 00:03:55 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/10 11:20:25 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/include/libft.h"

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
    // else
    // {
    //     format_list(av);
    // }
}

void format_string(char *str)
{
    char **ops_list;

    ops_list = ft_split(str, ' ');
    printf("%s\n", ops_list[0]);
}