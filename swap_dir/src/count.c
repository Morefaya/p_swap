/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:32:44 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:39:29 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_below(t_list *lst_a, int val)
{
	int	i;

	i = 0;
	while (lst_a)
	{
		if (((t_pile*)(lst_a->content))->val < val)
			i++;
		lst_a = lst_a->next;
	}
	return (i);
}

int	count_above(t_list *lst_a, int val)
{
	int	i;

	i = 0;
	while (lst_a)
	{
		if (((t_pile*)(lst_a->content))->val >= val)
			i++;
		lst_a = lst_a->next;
	}
	return (i);
}

int	count_btw(t_list *lst_a, int one, int two)
{
	int	i;
	int	val;

	i = 0;
	while (lst_a)
	{
		val = ((t_pile*)(lst_a->content))->val;
		if (val >= one && val < two)
			i++;
		lst_a = lst_a->next;
	}
	return (i);
}
