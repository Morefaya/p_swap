/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_high.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 16:36:05 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 16:56:51 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_high(t_list *lst, int val)
{
	t_list	*tmp;
	int		len;
	int		i;

	len = ft_lstcount(lst);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (((t_pile*)(tmp->content))->val > val)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
