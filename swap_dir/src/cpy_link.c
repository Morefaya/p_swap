/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 16:56:23 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 16:56:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cpy_link(t_list *lst)
{
	t_list	*cpy;
	t_pile	pile;

	pile.val = ((t_pile*)(lst->content))->val;
	if (!(cpy = ft_lstnew(&pile, sizeof(t_pile))))
		return ;
	ft_lstadd_back(lst, cpy);
	return ;
}
