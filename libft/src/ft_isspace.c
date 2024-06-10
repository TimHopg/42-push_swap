/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:28:19 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 16:30:11 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Returns true if char is horizontal tab, line feed, vertical tab, form feed
    carriage return or space, false otherwise.

*/

#include "../include/libft.h"

int	ft_isspace(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}
