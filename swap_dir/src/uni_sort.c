/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uni_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:08:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 20:08:55 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	uni_sort(t_list *lst_a, t_list *lst_b)
{
	int	i;

	i = 1;
	if (!lst_a || !lst_b)
		return (0);
	else if (!lst_a->next || !lst_b->next)
		return (0);
	while (lst_a->next && lst_b->next)
	{
		if (((t_pile*)(lst_a->content))->val\
			> ((t_pile*)(lst_a->next->content))->val
			&& ((t_pile*)(lst_b->content))->val\
			< ((t_pile*)(lst_b->next->content))->val)
			return (i);
		i++;
		lst_a = lst_a->next;
		lst_b = lst_b->next;
	}
	return (0);
}
