/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:28:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/20 17:44:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort(t_list **lst, int asc)
{
	int		lim_low;
	int		lim_high;
	int		higher;
	//int		lower;
	int		value;

	lim_low = get_lowest(*lst);
	lim_high = get_highest(*lst);
	if (asc)
	{
		if (asc)
		{
			ft_putendl("a");
			value = (((t_pile*)(*lst)->content))->val;
			if (value == lim_low)
			{
				higher = get_higher(*lst, lim_low);
				rotate(lst);
				while ((((t_pile*)(*lst)->content))->val == higher)
				{
					ft_putendl("b");
					lim_low = higher;
					higher = get_higher(*lst, lim_low);
					rotate(lst);
				}
				while ((((t_pile*)(*lst)->next->content))->val < lim_high)
				{
					ft_putendl("c");
					if (check_next(*lst))
						swap(lst);
					rotate(lst);
				}
			}
			else if (value == lim_high)
			{
				ft_putchar('@');
			}
		}
	}
}
