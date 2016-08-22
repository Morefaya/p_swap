/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:12:35 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/22 16:12:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_next(t_list *lst)
{
	if (!lst)
		return (-1);
	if (((t_pile*)(lst->content))->val > ((t_pile*)(lst->next->content))->val)
		return (1);
	else
		return (0);
}
