/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:43:33 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/22 16:56:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_trans(t_list **lst, int range)
{
	int	i;

	if (!range)
		return ;
	i = ft_abs(range);
	while (i--)
	{
		if (range < 0)
			rev_rotate(lst);
		swap(lst);
		if (range > 0)
			rotate(lst);
	}
}
