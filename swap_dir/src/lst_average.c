/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_average.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 13:26:28 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 13:35:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lst_average(t_list *lst)
{
	int		sum;
	int		nb_link;

	sum = 0;
	nb_link = ft_lstcount(lst);
	while (lst)
	{
		sum += ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (sum / nb_link);
}

int		lst_average_rest(t_list *lst)
{
	int		sum;
	int		nb_link;

	sum = 0;
	nb_link = ft_lstcount(lst);
	while (lst)
	{
		sum += ((t_pile*)(lst->content))->val;
		lst = lst->next;
	}
	return (sum % nb_link);
}
