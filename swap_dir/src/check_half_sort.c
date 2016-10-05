/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_half_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:01:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 17:01:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_half_sort(t_list *lst, int len)
{
	int	med;
	int	i;

	if (len > ft_lstcount(lst))
		return (0);
	med = lstmed_range(lst, len);
	i = 0;
	while (i++ <= len / 2)
	{
		if (((t_pile*)(lst->content))->val > med)
			return (1);
		lst = lst->next;
	}
	while (i++ < len)
	{
		if (((t_pile*)(lst->content))->val <= med)
			return (1);
		lst = lst->next;
	}
	return (0);
}
