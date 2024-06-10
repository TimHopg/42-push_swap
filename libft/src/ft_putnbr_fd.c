/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:03:04 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 16:52:15 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Outputs integer 'n' to given file descriptor.

*/

#include "../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char const	*base;

	base = "0123456789";
	ft_putbase_fd(n, base, fd);
}
