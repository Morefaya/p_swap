/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_low.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 16:19:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:40:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_low(t_list *lst, int val)
{
	t_list	*tmp;
	int		len;
	int		i;

	len = ft_lstcount(lst);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (((t_pile*)(tmp->content))->val < val)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
