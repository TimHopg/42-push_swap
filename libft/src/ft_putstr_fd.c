/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:55:11 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Outputs string 's' to given file descriptor.

*/

#include "../include/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
