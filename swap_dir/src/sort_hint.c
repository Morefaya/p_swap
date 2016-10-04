/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:17:41 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:20:58 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	f_part(t_hint *hint, int *i)
{
	p_local(hint->lst_a, hint->lst_b, hint->mark);
	r_local(hint->lst_b, hint->mark);
	(*i)++;
}

static void	s_part(t_hint *hint, int *i)
{
	p_local(hint->lst_a, hint->lst_b, hint->mark);
	if (ft_lstcount(*(hint->lst_b)) > 1)
	{
		if (!check_next(*(hint->lst_b)))
			s_local(hint->lst_b, hint->mark);
	}
	(*i)++;
}

void		sort_hint(t_hint *hint, int *i, int j)
{
	int		var;
	t_range	rg;

	bzero_rangval(&rg);
	init_rangval(&rg, hint->lst_data, j);
	var = ((t_pile*)(((t_list*)(*(hint->lst_a)))->content))->val;
	if (var >= rg.one && var < rg.two)
		f_part(hint, i);
	else if (var >= rg.three && var < rg.four)
		s_part(hint, i);
	else
	{
		hint->mark->asc = 1;
		if (check_rothint(hint, rg))
			r_local(hint->lst_a, hint->mark);
		else
			rev_local(hint->lst_a, hint->mark);
		hint->mark->asc = 0;
	}
}

void		sort_hint_2(t_hint *hint, int *i)
{
	int	var;
	int	first;
	int	last;

	first = get_first(hint->lst_data);
	last = get_last(hint->lst_data);
	var = ((t_pile*)(((t_list*)(*(hint->lst_a)))->content))->val;
	if (var < first)
	{
		p_local(hint->lst_a, hint->lst_b, hint->mark);
		r_local(hint->lst_b, hint->mark);
		(*i)++;
	}
	else if (var >= last)
	{
		p_local(hint->lst_a, hint->lst_b, hint->mark);
		(*i)++;
	}
}
