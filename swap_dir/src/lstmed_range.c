/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmed_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:00:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 21:00:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lstmed_range(t_list *lst, int range)
{
	t_lstmed	tmp;

	if (!lst)
		return (0);
	tmp.j = 0;
	tmp.nu_med = ((t_pile*)(lst->content))->val;
	tmp.tmp_1 = lst;
	while (tmp.tmp_1 && (tmp.j)++ < range)
	{
		tmp.tmp_2 = lst;
		tmp.i = 0;
		tmp.k = 0;
		while (tmp.tmp_2 && tmp.k++ < range)
		{
			if (((t_pile*)(tmp.tmp_2->content))->val\
				< ((t_pile*)(tmp.tmp_1->content))->val)
				(tmp.i)++;
			tmp.tmp_2 = tmp.tmp_2->next;
		}
		if (tmp.i == range / 2)
			tmp.nu_med = ((t_pile*)(tmp.tmp_1->content))->val;
		tmp.tmp_1 = tmp.tmp_1->next;
	}
	return (tmp.nu_med);
}
