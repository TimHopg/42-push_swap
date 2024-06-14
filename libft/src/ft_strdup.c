/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:55:45 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:42:00 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

String duplication. Allocates memory using malloc for new string and copies
	contents of original string incl. null termination.

*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	i;

	dup_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup_s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dup_s[i] = s[i];
	dup_s[i] = '\0';
	return (dup_s);
}
