/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:04:36 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 21:04:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "rra", mark->tab_op);
	else
		add_op(mark->op_lst, "rrb", mark->tab_op);
	rev_rotate(lst);
}

void	r_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "ra", mark->tab_op);
	else
		add_op(mark->op_lst, "rb", mark->tab_op);
	rotate(lst);
}

void	s_local(t_list **lst, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "sa", mark->tab_op);
	else
		add_op(mark->op_lst, "sb", mark->tab_op);
	swap(lst);
}

void	p_local(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	if (mark->asc)
		add_op(mark->op_lst, "pa", mark->tab_op);
	else
		add_op(mark->op_lst, "pb", mark->tab_op);
	push(lst_a, lst_b);
}
