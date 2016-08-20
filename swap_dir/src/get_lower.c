/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:37:31 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/20 16:49:30 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lower(t_list *lst, int val)
{
	int		nb_lower;
	t_list	*tmp;

	if (!lst)
		return (0);
	nb_lower = count_low(lst, val);
	tmp = lst;
	while (tmp)
	{
		if (count_low(lst, ((t_pile*)(tmp->content))->val) == nb_lower - 1)
			return (((t_pile*)(tmp->content))->val);
		tmp = tmp->next;
	}
	return (0);
}
