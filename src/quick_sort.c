/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:01:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 19:23:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list **lst_a, t_list **lst_b)
{
	int		nb_link;
	int		median;
	int		i;

	nb_link = ft_lstcount(*lst_a);
	median = lst_median(*lst_a);
	i = 0;
	while (i < nb_link)
	{
		if (((t_pile*)((*lst_a)->content))->val >= median)
			push(lst_a, lst_b);
		else
			rotate(lst_a);
		i++;
	}
	//while (*lst_a)
	//	push(lst_a, lst_b);
}
