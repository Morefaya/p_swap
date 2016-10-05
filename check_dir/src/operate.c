/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:09:21 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 20:36:14 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	operate_exit(t_list **lst_a, t_list **lst_b, t_list **op_lst)
{
	ft_putendl("Error");
	ft_lstdel(op_lst, (void(*)(void*, size_t))del_op);
	ft_lstdel(lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(lst_b, (void(*)(void*, size_t))del_content);
	exit(1);
}

static void	operate_next(t_list **lst_a, t_list **lst_b, t_list **op_lst)
{
	char	*op;

	op = ((t_op*)((*op_lst)->content))->op;
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
	else if (!ft_strcmp("", op))
		return ;
	else
		operate_exit(lst_a, lst_b, op_lst);
}

void		operate(t_list **lst_a, t_list **lst_b, t_list **op_lst)
{
	char	*op;

	op = ((t_op*)((*op_lst)->content))->op;
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
	else
		operate_next(lst_a, lst_b, op_lst);
}
