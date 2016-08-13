/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:01:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/13 19:34:28 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_sort(t_list **lst_a, t_list **lst_b, int opt)
{
	int	nb_link;
	int	median;
	int	i;
	int	ret;

	nb_link = ft_lstcount(*lst_a);
	median = lst_median(*lst_a);
	i = 0;
	ret = 0;
	while (i < nb_link)
	{
		if ((((t_pile*)((*lst_a)->content))->val < median && opt)
			|| (((t_pile*)((*lst_a)->content))->val >= median && !opt))
		{
			ret++;
			push(lst_a, lst_b);
			ft_putendl("P");
		}
		else
		{
			rotate(lst_a);
			ft_putendl("R");
		}
		i++;
	}
	return (ret);
}
