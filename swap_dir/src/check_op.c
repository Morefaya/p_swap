/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:37:02 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:37:53 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dbop(t_list **op)
{
	if ((!(ft_strcmp("sa", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("sa", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("sb", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("sb", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("ra", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("rra", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("rb", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("rrb", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("ra", ((t_op*)((*op)->next->content))->op))
		&& !(ft_strcmp("rra", ((t_op*)((*op)->content))->op)))
		|| (!(ft_strcmp("rb", ((t_op*)((*op)->next->content))->op))
		&& !(ft_strcmp("rrb", ((t_op*)((*op)->content))->op))))
		return (1);
	return (0);
}

static int	verif_op(t_list *op)
{
	if (!op)
		return (0);
	while (op->next)
	{
		if (check_dbop(&op))
			return (1);
		op = op->next;
	}
	return (0);
}

static void	reducer(t_list *tmp, t_list **op, t_list **trash)
{
	int	i;

	i = 0;
	while (tmp != *op)
	{
		rotate(op);
		i++;
	}
	push(op, trash);
	push(op, trash);
	while (i--)
		rev_rotate(op);
}

void		check_op(t_list **op)
{
	t_list	*tmp;
	t_list	*trash;

	while (verif_op(*op))
	{
		tmp = *op;
		trash = NULL;
		while (tmp && tmp->next)
		{
			if (check_dbop(&tmp))
				reducer(tmp, op, &trash);
			tmp = tmp->next;
		}
		ft_lstdel(&trash, (void(*)(void*, size_t))del_content);
	}
}
