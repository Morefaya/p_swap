/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:57:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 20:57:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tr(t_tree *tr)
{
	if (!tr)
		return ;
	ft_printf("%d\n", ((t_pile*)(tr->content))->val);
	print_tr(tr->left);
	print_tr(tr->right);
}
