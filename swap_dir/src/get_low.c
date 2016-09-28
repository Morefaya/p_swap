/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_low.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:27:23 by jcazako           #+#    #+#             */
/*   Updated: 2016/09/28 18:27:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_low(t_list *lst, int len)
{
	int		low;

	if (!lst)
		return (0);
	low = ((t_pile*)(lst->content))->val;
	while (lst && len--)
	{
		if (((t_pile*)(lst->content))->val < low)
			low = ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (low);
}
