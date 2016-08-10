/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:42:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 13:02:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_list **lst_a, t_list **lst_b)
{
	int	low;
	int	count;
	
	count = 0;
	while (*lst_a)
	{
		low = ((t_pile*)((*lst_a)->content))->val;
		rotate(lst_a);
		ft_putendl("ra");
		count++;
		while (low != ((t_pile*)((*lst_a)->content))->val)
		{
			if (((t_pile*)((*lst_a)->content))->val < low)
				low = ((t_pile*)((*lst_a)->content))->val;
			rotate(lst_a);
			ft_putendl("ra");
			count++;
		}
		push(lst_a, lst_b);
		ft_putendl("pb");
		count++;
	}
	while (*lst_b)
	{
		push(lst_b, lst_a);
		ft_putendl("pa");
		count++;
	}
	ft_putchar('\n');
	ft_putnbr(count);
	ft_putchar('\n');
}
