/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:23:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:23:04 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_prev(t_list *lst)
{
	if (!lst)
		return (0);
	else if (!lst->next)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (((t_pile*)(lst->content))->val);
}
