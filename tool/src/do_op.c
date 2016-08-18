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

#include "tool.h"

static void	operate_2(t_list **lst_a, t_list **lst_b, char *op)
{
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
	else
		ft_putendl_fd("invalid instructions", 2);
}

static void	operate_1(t_list **lst_a, t_list **lst_b, char *op)
{
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
		operate_2(lst_a, lst_b, op);
}

void		do_op(t_list **lst_a, t_list **lst_b)
{
	char	*line;
	int	i;

	i = 0;
	while (get_next_line(0, &line))
	{
		operate_1(lst_a, lst_b, line);
		print_lst(*lst_a);
		print_lst(*lst_b);
		ft_putchar('\n');
		free(line);
		i++;
	}
	free(line);
	ft_putstr("\t\t\t\t\t\t\t\tnbre d'operation: ");
	ft_putnbr(i);
	ft_putchar('\n');
}
