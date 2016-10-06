/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 15:06:53 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 16:23:17 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lst_median(t_list *lst)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		nu_med;
	int		i;

	if (!lst)
		return (0);
	nu_med = ((t_pile*)(lst->content))->val;
	tmp_1 = lst;
	while (tmp_1)
	{
		tmp_2 = lst;
		i = 0;
		while (tmp_2)
		{
			if (((t_pile*)(tmp_2->content))->val\
				< ((t_pile*)(tmp_1->content))->val)
				i++;
			tmp_2 = tmp_2->next;
		}
		if (i == ft_lstcount(lst) / 2)
			nu_med = ((t_pile*)(tmp_1->content))->val;
		tmp_1 = tmp_1->next;
	}
	return (nu_med);
}
