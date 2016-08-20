/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_higher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 16:51:39 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/20 16:55:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_higher(t_list *lst, int val)
{
	int		nb_higher;
	t_list	*tmp;

	if (!lst)
		return (0);
	nb_higher = count_high(lst, val);
	tmp = lst;
	while (tmp)
	{
		if (count_high(lst, ((t_pile*)(tmp->content))->val) == nb_higher - 1)
			return (((t_pile*)(tmp->content))->val);
		tmp = tmp->next;
	}
	return (0);
}
