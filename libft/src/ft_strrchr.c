/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:42:02 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:42:00 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Returns pointer to last occurrence of c in string s or NULL if not found.

*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*found_ptr;

	i = 0;
	found_ptr = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			found_ptr = (char *)(s + i);
		i++;
	}
	if ((char)c == '\0')
		found_ptr = (char *)s + i;
	return (found_ptr);
}
