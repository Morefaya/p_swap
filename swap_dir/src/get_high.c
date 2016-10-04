/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_high.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:52:32 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 21:52:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_high(t_list *lst, int len)
{
	int		high;

	if (!lst)
		return (0);
	high = ((t_pile*)(lst->content))->val;
	while (lst && len--)
	{
		if (((t_pile*)(lst->content))->val > high)
			high = ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (high);
}
