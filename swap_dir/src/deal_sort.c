/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:18:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 19:18:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	deal_1(t_hint hint, int tmp)
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
}
