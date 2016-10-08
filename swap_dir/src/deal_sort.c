/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:18:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/08 16:33:38 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	deal_rot(t_hint hint, int tmp)
{
	if (tmp > 0)
		r_local(hint.lst_b, hint.mark);
	else
		rev_local(hint.lst_b, hint.mark);
}

static void	deal_tmp(int *tmp)
{
	if (*tmp > 0)
		(*tmp)--;
	else
		(*tmp)++;
}

static void	deal(t_hint hint, int tmp, t_next *next)
{
	int		val;
	int		done;

	done = 0;
	hint.mark->asc = 0;
	val = ((t_pile*)((*(hint.lst_b))->content))->val;
	while (val != next->high)
	{
		deal_rot(hint, tmp);
		val = ((t_pile*)((*(hint.lst_b))->content))->val;
		if (val == next->val && ft_abs(tmp) > 1)
		{
			hint.mark->asc = 1;
			p_local(hint.lst_b, hint.lst_a, hint.mark);
			ft_lstdel_range(next->cpy_s, 2, del_content);
			done = 1;
			hint.mark->asc = 0;
		}
		deal_tmp(&tmp);
	}
	hint.mark->asc = 1;
	p_local(hint.lst_b, hint.lst_a, hint.mark);
	ft_lstdel_range(next->cpy_s, 1, del_content);
	if (done)
		s_local(hint.lst_a, hint.mark);
}

void		deal_sort(t_hint hint, t_list **cpy_s)
{
	int		tmp;
	t_next	next;

	ft_lstrev(cpy_s);
	next.cpy_s = cpy_s;
	while (*cpy_s)
	{
		hint.mark->asc = 1;
		next.high = ((t_pile*)((*cpy_s)->content))->val;
		if (ft_lstcount(*cpy_s) > 1)
			next.val = ((t_pile*)((*cpy_s)->next->content))->val;
		else
			next.val = ((t_pile*)((*(hint.lst_b))->content))->val;
		tmp = seek_way(*(hint.lst_b), next.high);
		if (!tmp)
		{
			p_local(hint.lst_b, hint.lst_a, hint.mark);
			ft_lstdel_range(cpy_s, 1, del_content);
		}
		else
			deal(hint, tmp, &next);
	}
	hint.mark->asc = 0;
}
