/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prevnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:58:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 16:58:15 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_prevnext(t_list *lst)
{
	int	value_next;
	int	value_prev;

	if (!lst)
		return (-1);
	else if (!lst->next)
		return (-1);
	value_next = ((t_pile*)(lst->next->content))->val;
	while (lst->next)
		lst = lst->next;
	value_prev = ((t_pile*)(lst->content))->val;
	if (value_next > value_prev)
		return (1);
	else
		return (0);
}
