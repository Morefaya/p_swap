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

/*static void	rev_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "rra", mark->tab_op);
	else
		add_op(mark->op_lst, "rrb", mark->tab_op);
	rev_rotate(lst);
}

static void	r_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "ra", mark->tab_op);
	else
		add_op(mark->op_lst, "rb", mark->tab_op);
	rotate(lst);
}

static void	s_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "sa", mark->tab_op);
	else
		add_op(mark->op_lst, "sb", mark->tab_op);
	swap(lst);
}*/

static void	help_low(t_list **lst, int high, t_mark *mark)
{
	if (get_next(*lst) == high)
	{
		if (mark->asc)
		{
			s_local(lst, mark);
			r_local(lst, mark);
		}
		else
			r_local(lst, mark);
	}
	else if (get_prev(*lst) == high)
	{
		if (!mark->asc)
		{
			rev_local(lst, mark);
			s_local(lst, mark);
			r_local(lst, mark);
		}
	}
}

static void	help_high(t_list **lst, int low, t_mark *mark)
{
	if (get_next(*lst) == low)
	{
		if (!mark->asc)
		{
			s_local(lst, mark);
			r_local(lst, mark);
		}
		else if (mark->asc)
			r_local(lst, mark);
	}
	else if (get_prev(*lst) == low)
	{
		if (mark->asc)
		{
			rev_local(lst, mark);
			s_local(lst, mark);
			r_local(lst, mark); /*facultative*/
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


static void    lst_trans_local(t_list **lst, int range, t_mark *mark)
{
        int	i;

	if (!range)
		return ;
	i = ft_abs(range);
	while (i--)
	{
		if (range < 0)
			rev_local(lst, mark);
		s_local(lst, mark);
		if (range > 0)
			r_local(lst, mark);
	}
}

void		jc_sort(t_list **lst, int asc, t_mark *mark)
{
	t_sort	data;
	int		i;

	init_sort(lst, &data);
	mark->asc = asc;
	i = 0;
	if (data.rot > 0)
		while (i++ < data.rot)
			r_local(lst, mark);
	else if (data.rot < 0)
		while (i++ < ft_abs(data.rot))
			rev_local(lst, mark);
	if (data.rot == data.r_low)
	{
		lst_trans_local(lst, where_is(*lst, data.high), mark);
		help_low(lst, data.high, mark);
	}
	else if (data.rot == data.r_high)
	{
		lst_trans_local(lst, where_is(*lst, data.low), mark);
		help_high(lst, data.low, mark);
	}
}
