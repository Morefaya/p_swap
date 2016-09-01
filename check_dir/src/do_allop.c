/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_allop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:15:13 by jcazako           #+#    #+#             */
/*   Updated: 2016/09/01 18:48:08 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		do_allop(t_list **lst_a, t_list **lst_b, t_list **op_lst)
{
	int		len;
	int		i;

	i = 0;
	len = ft_lstcount(*op_lst);
	while (i++ < len)
	{
		operate(lst_a, lst_b, op_lst);
		rotate(op_lst);
	}
}
