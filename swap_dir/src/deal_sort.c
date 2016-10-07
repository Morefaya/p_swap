/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:18:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 22:41:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	deal_1(t_hint hint, int tmp, t_next *next)
{
	int		val;
	int	done;

	done = 0;
	hint.mark->asc = 0;
	next->e = 1;
	val = ((t_pile*)((*(hint.lst_b))->content))->val;	
	while (val != next->high)
	{
		if (tmp > 0)
			r_local(hint.lst_b, hint.mark);
		else
			rev_local(hint.lst_b, hint.mark);
		val = ((t_pile*)((*(hint.lst_b))->content))->val;	
		if (val == next->val && ft_abs(tmp) > 1)
		{
			hint.mark->asc = 1;
			p_local(hint.lst_b, hint.lst_a, hint.mark);
			ft_lstdel_range(next->cpy_s, 2, del_content);
			done = 1;
			hint.mark->asc = 0;
		}
		if (tmp > 0)
			tmp--;
		else
			tmp++;
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
	t_next		next;

	ft_lstrev(cpy_s);
	next.cpy_s = cpy_s;
	while (*cpy_s)
	{
		hint.mark->asc = 1;
		next.high = ((t_pile*)((*cpy_s)->content))->val;
		if (ft_lstcount(*cpy_s) > 1)
		{
			next.e = 1;
			next.val = ((t_pile*)((*cpy_s)->next->content))->val;
		}
		else
		{
			next.e = 0;
			next.val = ((t_pile*)((*(hint.lst_b))->content))->val;
		}	
		tmp = seek_way(*(hint.lst_b), next.high);
		if (!tmp)
		{
			p_local(hint.lst_b, hint.lst_a, hint.mark);
			ft_lstdel_range(cpy_s, 1, del_content);
		}
		else
			deal_1(hint, tmp, &next);
	}
	hint.mark->asc = 0;
}
