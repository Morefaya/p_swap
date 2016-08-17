/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 18:09:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/16 20:10:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_list **lst_a, t_list **lst_b)
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
			push(lst_a, lst_b);
			i++;
		}
		rotate(lst_a);
		print_lst(*lst_a);
		print_lst(*lst_b);
		ft_putchar('\n');
	}
	i = 0;
	median = lst_median(*lst_b);
	nb_link = ft_lstcount(*lst_b);
	while (i < nb_link / 2)
	{
		if (((t_pile*)((*lst_b)->content))->val < median)
		{
			push(lst_b, lst_a);
			i++;
		}
		rotate(lst_b);
		print_lst(*lst_a);
		print_lst(*lst_b);
		ft_putchar('\n');
	}
	i = 0;
	ft_putendl("dance and dab");
	median = lst_median(*lst_a);
	nb_link = ft_lstcount(*lst_a);
	while (i < nb_link / 2)
	{
		if (((t_pile*)((*lst_a)->content))->val < median)
		{
			push(lst_a, lst_b);
			i++;
		}
		rotate(lst_a);
		print_lst(*lst_a);
		print_lst(*lst_b);
		ft_putchar('\n');
	}
}
