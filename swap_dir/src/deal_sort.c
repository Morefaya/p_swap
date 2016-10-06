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

/*static void	deal_1(t_hint hint, int tmp)
{
	hint.mark->asc = 0;
	while (tmp--)
		r_local(hint.lst_b, hint.mark);
	hint.mark->asc = 1;
	p_local(hint.lst_b, hint.lst_a, hint.mark);
}

static void	deal_2(t_hint hint, int tmp)
{
	hint.mark->asc = 0;
	while (tmp++)
		rev_local(hint.lst_b, hint.mark);
	hint.mark->asc = 1;
	p_local(hint.lst_b, hint.lst_a, hint.mark);
}

void		deal_sort(t_hint hint, t_list *cpy_s)
{
	int		val;
	int		tmp;
	int		high;

	if (cpy_s->next)
		deal_sort(hint, cpy_s->next);
	val = ((t_pile*)((*(hint.lst_b))->content))->val;
	high = ((t_pile*)(cpy_s->content))->val;
	hint.mark->asc = 1;
	if (val == high)
		p_local(hint.lst_b, hint.lst_a, hint.mark);
	else if ((tmp = seek_way(*(hint.lst_b), high)) > 0)
		deal_1(hint, tmp);
	else
		deal_2(hint, tmp);
	hint.mark->asc = 0;
}*/

static void	deal_1(t_hint hint, int tmp, t_next next)
{
	int		val;

	hint.mark->asc = 0;
	while (tmp--)
	{
		r_local(hint.lst_b, hint.mark);
		val = ((t_pile*)((*(hint.lst_b))->content))->val;	
		if (next.e && val == next.val)
		{
			p_local(hint.lst_b, hint.lst_a, hint.mark);
			tmp--;
			ft_lstpush();
		}
	}
	hint.mark->asc = 1;
	p_local(hint.lst_b, hint.lst_a, hint.mark);
}

void		deal_sort(t_hint hint, t_list **cpy_s)
{
	int		val;
	int		tmp_1;
	int		tmp_2;
	int		high;
	int		next;
	t_list	*trash;

	ft_lstrev(cpy_s);
	hint.mark->asc = 1;
	while (*cpy_s)
	{
		val = ((t_pile*)((*(hint.lst_b))->content))->val;
		high = ((t_pile*)(cpy_s->content))->val;
		if (ft_lstcount(*cpys) > 1)
			next = ((t_pile*)((*cpy_s)->next->content))->val;
		hint.mark->asc = 1;
		tmp = seek_way(*(hint.lst_b), high);
		if (!tmp)
		{
			p_local(hint.lst_b, hint.lst_a, hint.mark);
			ft_lstpush(cpy_s, &trash);
		}
		else if (tmp > 0)
			deal_1(hint, tmp);
		else
			deal_2(hint, tmp);
	}
	hint.mark->asc = 0;

}
