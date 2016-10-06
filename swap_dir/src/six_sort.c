/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:59:37 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 20:10:58 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	end_it(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	mark->asc = 1;
	three_sort(lst_a, mark);
	mark->asc = 0;
	if (!check_next(*lst_b))
		s_local(lst_b, mark);
	while (*lst_b)
	{
		mark->asc = 1;
		p_local(lst_b, lst_a, mark);
		mark->asc = 0;
	}
}

void		six_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int	var;
	int	med;
	int	len;
	int	i;

	med = lst_median(*lst_a);
	len = ft_lstcount(*lst_a);
	i = 0;
	while (i < len / 2)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < med)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else
		{
			mark->asc = 1;
			r_local(lst_a, mark);
			mark->asc = 0;
		}
	}
	end_it(lst_a, lst_b, mark);
}
