/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:51:42 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/09 14:56:44 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!*lst)
		return ;
	else if (!(*lst)->next)
		return ;
	tmp_1 = *lst;
	*lst = (*lst)->next;
	tmp_1->next = NULL;
	tmp_2 = *lst;
	while (tmp_2->next)
		tmp_2 = tmp_2->next;
	tmp_2->next = tmp_1;
}
