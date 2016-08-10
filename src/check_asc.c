/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 19:30:41 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 20:52:24 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ascending(t_list *lst)
{
	while (lst->next)
	{
		if (((t_pile*)(lst->content))->val\
				<= ((t_pile*)(lst->next->content))->val)
			return (0);
		lst = lst->next;
	}
	return (-1);
}

static int	descending(t_list *lst)
{
	while (lst->next)
	{
		if (((t_pile*)(lst->content))->val\
				>= ((t_pile*)(lst->next->content))->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int			check_asc(t_list *lst)
{
	if (!lst)
		return (0);
	else if (!lst->next)
		return (1);
	if (((t_pile*)(lst->content))->val > ((t_pile*)(lst->next->content))->val)
		return (ascending(lst));
	else
		return (descending(lst));
}
