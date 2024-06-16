/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:23:28 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/16 12:47:01 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void first_check(t_stk **a)
// {
//   char *line;
  
//   line = get_next_line(0);
//   if 
// }

void attempt_sort(t_stk **a)
{
    char *line;

    (void)a;
    line = get_next_line(0);
    while (line)
    {
        ft_printf("line\n");
        free(line);
        line = get_next_line(0);
    }
    free(line);
}

int main(int ac, char **av)
{
    t_stk *a;

    a = NULL;
    if (parse_input(ac, av, &a) < 0)
		  return (-1);
    attempt_sort(&a);
    if (is_ordered(&a))
        ft_putstr_fd("OK\n", 1);
    else if (!is_ordered(&a))
        ft_putstr_fd("KO\n", 1);
    free_stk(a);
    return (0);
}

