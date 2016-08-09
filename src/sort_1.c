/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:42:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/09 16:28:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_list **lst_a, t_list **lst_b)
{
	int	low;
	
	low = ((t_pile)(*(lst_a)->content)).val;
	rotate(lst_a);
	while (low != ((t_pile)(*(lst_a)->content)).val)
	{
		if (((t_pile)(*(lst_a)->content)).val < low)
			low = ((t_pile)(*(lst_a)->content)).val;
		rotate(&lst_a);
	}
	push(lst_a, lst_b);
}
