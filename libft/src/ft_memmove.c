/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:56:54 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Copies data from back or front of src to dest depending on whether
	dest is before or after src in memory. To account for potential overlaps.

*/

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_copy;
	const char	*src_copy;

	dest_copy = dest;
	src_copy = src;
	if (dest_copy < src_copy)
		while (len--)
			*dest_copy++ = *src_copy++;
	else if (dest_copy > src_copy)
	{
		dest_copy += len;
		src_copy += len;
		while (len--)
			*(--dest_copy) = *(--src_copy);
	}
	return (dest);
}
