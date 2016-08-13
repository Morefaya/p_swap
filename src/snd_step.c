/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snd_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:19:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/13 20:06:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		snd_step(t_list **lst, int opt)
{
	int		value;
	int		value_next;
	int		high;
	int		low;

	if (!lst)
		return ;
	high = get_highest(*lst);
	low = get_lowest(*lst);
	while (((check_asc_rot(*lst) != 1) && opt)
		|| ((check_asc_rot(*lst) != -1) && !opt))
	{
		value = (((t_pile*)(*lst)->content))->val;
		value_next = (((t_pile*)(*lst)->next->content))->val;
		if ((value > value_next && value != high && opt)
			|| (value < value_next && value != low && !opt))
		{
			ft_putendl("Sa");
			swap(lst);
		}
		rotate(lst);
		ft_putendl("Ra");
	}
	turn_list(lst);
}
