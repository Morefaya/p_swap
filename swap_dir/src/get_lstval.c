/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:24:24 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:24:25 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lstval(t_list *lst, int range)
{
	while (lst && range--)
		lst = lst->next;
	return (((t_pile*)(lst->content))->val);
}
