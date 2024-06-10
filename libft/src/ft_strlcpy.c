/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:54:53 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 15:18:12 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Copies at most dstsize - 1 bytes from src to dest truncating src if necessary.
The destination string is always null terminated.
Returns total length of string that was attempted to create (len of src).

Check for buffer overflow as follows:
if (strlcpy(dst, src, dstsize) >= dstsize)
        return −1;
		
*/

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	const char	*src_ptr;

	src_ptr = src;
	if (dstsize > 0)
	{
		while (*src_ptr && dstsize-- > 1)
			*dest++ = *src_ptr++;
		*dest = '\0';
	}
	return (ft_strlen(src));
}
