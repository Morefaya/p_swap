/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rangval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:17:19 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:17:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_rangval(t_range *r_val, t_list *lst_data, int j)
{
	int	k;
	int	l;
	int	len;

	len = ft_lstcount(lst_data);
	k = len / 2 - j - 1;
	if (k < 0)
		return ;
	l = 0;
	while (l < k)
	{
		lst_data = lst_data->next;
		l++;
	}
	r_val->one = ((t_pile*)(lst_data->content))->val;
	r_val->two = ((t_pile*)(lst_data->next->content))->val;
	k = len / 2 + j;
	while (l < k)
	{
		lst_data = lst_data->next;
		l++;
	}
	r_val->three = ((t_pile*)(lst_data->content))->val;
	r_val->four = ((t_pile*)(lst_data->next->content))->val;
}
