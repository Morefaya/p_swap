/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:31:55 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:31:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	operate_2(t_list **lst_a, t_list **lst_b, t_list *op_lst)
{
	char	*op;

	op = ((t_op*)(op_lst->content))->op;
	if (!ft_strcmp("ra", op))
		rotate(lst_a);
	else if (!ft_strcmp("rb", op))
		rotate(lst_b);
	else if (!ft_strcmp("rr", op))
	{
		rotate(lst_a);
		rotate(lst_b);
	}
	else if (!ft_strcmp("rra", op))
		rev_rotate(lst_a);
	else if (!ft_strcmp("rrb", op))
		rev_rotate(lst_b);
	else if (!ft_strcmp("rrr", op))
	{
		rev_rotate(lst_a);
		rev_rotate(lst_b);
	}
}

static void	operate_1(t_list **lst_a, t_list **lst_b, t_list *op_lst)
{
	char	*op;

	op = ((t_op*)(op_lst->content))->op;
	if (!ft_strcmp("sa", op))
		swap(lst_a);
	else if (!ft_strcmp("sb", op))
		swap(lst_b);
	else if (!ft_strcmp("ss", op))
	{
		swap(lst_a);
		swap(lst_b);
	}
	else if (!ft_strcmp("pa", op))
		push(lst_b, lst_a);
	else if (!ft_strcmp("pb", op))
		push(lst_a, lst_b);
	operate_2(lst_a, lst_b, op_lst);
}

void		do_op(t_list **lst_a, t_list **lst_b, t_list *op_lst)
{
	while (op_lst)
	{
		operate_1(lst_a, lst_b, op_lst);
		op_lst = op_lst->next;
	}
}
