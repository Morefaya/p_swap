/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:10:48 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/22 16:10:50 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	asc_sort(t_list **lst)
{
	if (!lst)
		return (0);
	else if (!*lst)
		return (0);
	else if (!(*lst)->next)
		return (0);
	if (check_asc_rot(*lst) != 1)
	{
		if (!check_prev(*lst) && !check_next(*lst))
		{
			if (check_prevnext(*lst))
				return (REV);
			else
				return (R);
		}
		else if (check_prev(*lst) && !check_next(*lst))
			return (R);
		else if (!check_prev(*lst) && check_next(*lst))
			return (S);
		else if (check_prev(*lst) && check_next(*lst))
			return (S);
	}
	return (0);
}
