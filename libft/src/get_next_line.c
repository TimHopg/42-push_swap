/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:31:03 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/15 00:40:04 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_clean_buffer(char *buffer);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

/*
 * Checks for negative (or zero) BUFFER_SIZE. Then performs read fail check
 * Clears pertinent fd and returns NULL if read returns error (-1).
 * Reads from buffer and returns new line.
 */

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (fd < 0 || fd >= FOPEN_MAX)
			return (NULL);
		buffer[fd][0] = '\0';
		return (NULL);
	}
	line = NULL;
	while ((buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0))
	{
		line = ft_strjoin_gnl(line, buffer[fd]);
		if (ft_clean_buffer(buffer[fd]) == 1)
			break ;
	}
	return (line);
}
