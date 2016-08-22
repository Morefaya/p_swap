/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jc_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 15:47:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/22 16:56:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	help_low(t_list **lst, int high, int asc)
{
	if (get_next(*lst) == high)
	{
		if (asc)
		{
			swap(lst);
			rotate(lst);
		}
		else
			rotate(lst);
	}
	else if (get_prev(*lst) == high)
	{
		if (!asc)
		{
			rev_rotate(lst);
			swap(lst);
			rotate(lst);
		}
	}
}

static void	help_high(t_list **lst, int low, int asc)
{
	if (get_next(*lst) == low)
	{
		if (!asc)
		{
			swap(lst);
			rotate(lst);
		}
		else if (asc)
			rotate(lst);
	}
	else if (get_prev(*lst) == low)
	{
		if (asc)
		{
			rev_rotate(lst);
			swap(lst);
			rotate(lst); //facultative			
		}
	}
}

static void	init_sort(t_list **lst, t_sort *data)
{
	data->high = get_highest(*lst);
	data->low = get_lowest(*lst);
	data->r_high = where_is(*lst, data->high);
	data->r_low = where_is(*lst, data->low);
	data->rot = (ft_abs(data->r_low) <= ft_abs(data->r_high))\
		? data->r_low : data->r_high;
}

void		jc_sort(t_list **lst, int asc)
{
	t_sort	data;
	int		i;

	init_sort(lst, &data);
	i = 0;
	if (data.rot > 0)
		while (i++ < data.rot)
			rotate(lst);
	else if (data.rot < 0)
		while (i++ < ft_abs(data.rot))
			rev_rotate(lst);
	if (data.rot == data.r_low)
	{
		lst_trans(lst, where_is(*lst, data.high));
		help_low(lst, data.high, asc);
	}
	else if (data.rot == data.r_high)
	{
		lst_trans(lst, where_is(*lst, data.low));
		help_high(lst, data.low, asc);
	}
}
