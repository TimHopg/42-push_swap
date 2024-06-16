/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:23:28 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/16 10:29:27 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stk *a;
    t_stk *b;

    a = NULL;
    b = NULL;

    if (parse_input(ac, av, &a) < 0)
		return (-1);
    (void)b;
    return (0);
}
