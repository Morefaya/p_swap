/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:58:45 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 16:58:46 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_prev(t_list *lst)
{
	int		tmp;

	if (!lst)
		return (-1);
	tmp = ((t_pile*)(lst->content))->val;
	while (lst->next)
		lst = lst->next;
	if (tmp > ((t_pile*)(lst->content))->val)
		return (1);
	else
		return (0);
}
