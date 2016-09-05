/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:09:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 20:58:50 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int		median;
	int		nb_link;
	int		i;

	i = 0;
	median = lst_median(*lst_a);
	nb_link = ft_lstcount(*lst_a);
	while (i < nb_link / 2)
	{
		if (((t_pile*)((*lst_a)->content))->val < median)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else
			r_local(lst_a, mark);
	}
	return (i);
}
