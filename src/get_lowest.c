/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lowest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 18:36:15 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/13 18:43:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lowest(t_list *lst)
{
	int		low;

	if (!lst)
		return (0);
	low = ((t_pile*)(lst->content))->val;
	while (lst)
	{
		if (((t_pile*)(lst->content))->val < low)
			low = ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (low);
}
