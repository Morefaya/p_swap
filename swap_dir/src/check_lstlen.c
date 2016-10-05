/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lstlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:00:21 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 17:00:23 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lstlen(t_list *lst, int div)
{
	if (!lst)
		return (1);
	while (lst)
	{
		if (((t_pile*)(lst->content))->val > div)
			return (1);
		lst = lst->next;
	}
	return (0);
}
