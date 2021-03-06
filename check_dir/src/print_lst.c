/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 18:04:31 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/09 13:08:36 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(((t_pile*)(lst->content))->val);
		ft_putchar('\t');
		lst = lst->next;
	}
	ft_putchar('\n');
}
