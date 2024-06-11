/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:55:36 by thopgood          #+#    #+#             */
/*   Updated: 2024/06/11 11:21:23 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_min(t_stack *head)
{
    t_stack *curr;
    int min;

    curr = head;
    min = curr->content;
    while (curr)
    {
        if (curr->content < min)
            min = curr->content;
        curr = curr->next;
    }
    return min;
}
