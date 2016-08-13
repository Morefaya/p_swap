/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snd_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:19:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/13 19:21:40 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		snd_step(t_list **lst, int opt)
{
	int		value;
	int		value_next;
	int		high;
	int		low;

	high = get_highest(*lst);
	low = get_lowest(*lst);
	while (((check_asc_rot(*lst) != 1) && opt)
		|| ((check_asc_rot(*lst) != -1) && !opt))
	{
		//print_lst(*lst);
		//ft_putchar('\n');
		value = (((t_pile*)(*lst)->content))->val;
		value_next = (((t_pile*)(*lst)->next->content))->val;
		if ((value > value_next && value != high && opt)
			|| (value < value_next && value != low && !opt))
			swap(lst);
		rotate(lst);
	}
	turn_list(lst);
	//print_lst(*lst);
	//ft_putchar('\n');
}