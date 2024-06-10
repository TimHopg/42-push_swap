/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:16:00 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Copies values of n bytes from src to dest.
Mutable copies are made (and cast) to ensure byte by byte transfer.

*/

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;

	if (dest == src)
		return (dest);
	dest_cpy = (char *)dest;
	src_cpy = (const char *)src;
	while (n-- > 0)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
