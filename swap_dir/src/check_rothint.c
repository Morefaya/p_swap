/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rothint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:57:46 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 17:05:12 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_rothint(t_hint *hint, t_range rg)
{
	int		i;
	int		len;
	int		var;
	t_list	*lst_a;

	i = 0;
	lst_a = *(hint->lst_a);
	len = ft_lstcount(lst_a);
	while (lst_a)
	{
		var = ((t_pile*)(lst_a->content))->val;
		if ((var >= rg.one && var < rg.two)
			|| (var >= rg.three && var < rg.four))
			break ;
		i++;
		lst_a = lst_a->next;
	}
	if (i <= len / 2)
		return (1);
	else
		return (0);
}
