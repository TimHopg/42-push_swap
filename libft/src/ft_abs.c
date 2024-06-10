/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:52:24 by thopgood          #+#    #+#             */
/*   Updated: 2024/04/23 16:54:05 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

returns the absolute value of a long

*/

#include "../include/libft.h"

long	ft_abs(long n)
{
	long	n_long;

	n_long = n;
	return (n_long *= ((n_long > 0) - (n_long < 0)));
}
