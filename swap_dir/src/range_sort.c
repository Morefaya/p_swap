/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 13:28:27 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/20 20:08:45 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	range_sort(t_list **lst, int asc)
{
	int		lim_low;
	int		lim_high;
	int		higher;
	int		lower;
	int		value;
	//int		i;

	lim_low = get_lowest(*lst);
	lim_high = get_highest(*lst);
	if (asc)
	{
		rotate(lst);
		//i = 0;
		while (check_asc_rot(*lst) != 1)
		{
			ft_putendl("a");
			value = (((t_pile*)(*lst)->content))->val;
			if (get_prev(*lst) == lim_low)
			{
				higher = get_higher(*lst, lim_low);
				rotate(lst);
				ft_putchar('@');
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
			else if ((((t_pile*)(*lst)->next->content))->val == lim_high)
			{
				lower = get_lower(*lst, lim_high);
				rev_rotate(lst);
				ft_putchar('d');
				while ((((t_pile*)(*lst)->content))->val == lower)
				{
					ft_putchar('e');
					lim_high = lower;
					lower = get_lower(*lst, lim_high);
					rev_rotate(lst);
				}
				while (get_prev(*lst) != lim_low)
				{
					ft_putchar('f');
					rev_rotate(lst);
					if (check_next(*lst))
						swap(lst);
				}
			}
			print_lst(*lst);
			ft_putchar('\n');
		}
	}
}
