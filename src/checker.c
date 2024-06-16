/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:23:28 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/16 18:09:27 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Check leaks

/*
 * Reads instructions from the standard input line by line using
 * GNL. Actuates each instruction on the stacks and returns an
 * error if a bad instruction is given.
 */

int	attempt_sort(t_stk **a)
{
	t_stk	*b;
	char	*line;
	int		rtn_code;

	b = NULL;
	rtn_code = 0;
	line = get_next_line(0);
	while (line)
	{
		if (interpret_instruction(a, &b, line) < 0)
		{
			rtn_code = -1;
			break ;
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free_stk(b);
	return (rtn_code);
}

/*
 * parses argc, argv input. Sorts stacks using instructions given.
 * Reports whether list has been successfully sorted or not (or
 * an error encountered)
 */

int	main(int ac, char **av)
{
	t_stk	*a;
	int		err_code;

	a = NULL;
	err_code = 0;
	if (parse_input(ac, av, &a) < 0)
		return (-1);
	if (attempt_sort(&a) < 0)
		err_code = -1;
	if (is_ordered(&a) && err_code >= 0)
		ft_putstr_fd("OK\n", 1);
	else if (!is_ordered(&a) && err_code >= 0)
		ft_putstr_fd("KO\n", 1);
	free_stk(a);
	return (0);
}

// ft_printf("Before\n");
// ft_print_stk(a, 'a');
// ft_printf("\n");
// ft_printf("\n");
// ft_printf("After\n");
// ft_print_stk(a, 'a');
