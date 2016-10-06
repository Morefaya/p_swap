/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 19:25:38 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 19:40:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **lst, t_mark *mark)
{
	if (check_asc(*lst) == 1)
		return ;
	if (check_next(*lst))
		s_local(lst, mark);
	if (check_asc(*lst) != 1)
		rev_local(lst, mark);
	if (check_next(*lst))
		s_local(lst, mark);
}
