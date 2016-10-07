/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 20:08:37 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_var(t_main *m_var, int ac, char **av)
{
	int		opt;

	m_var->lst_b = NULL;
	m_var->op = NULL;
	if (!(m_var->lst_a = deal_arg(ac, &opt, av)))
		return (1);
	if (!(m_var->tab_op = init_op()))
	{
		ft_lstdel(&(m_var->lst_a), (void(*)(void*, size_t))del_content);
		return (2);
	}
	return (0);
}

int			short_len(t_main *m_var, t_mark *mark)
{
	mark->asc = 1;
	three_sort(&m_var->lst_a, mark);
	mark->asc = 0;
	print_op(m_var->op);
	/*ft_printf("lst_a :");
	print_lst(m_var->lst_a);
	ft_printf("lst_b :");
	print_lst(m_var->lst_b);*/
	ft_lstdel(&m_var->lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&m_var->lst_b, (void(*)(void*, size_t))del_content);
	free_init(m_var->tab_op);
	ft_lstdel(&m_var->op, (void(*)(void*, size_t))del_content);
	return (0);
}

int			mid_len(t_main *m_var, t_mark *mark)
{
	six_sort(&m_var->lst_a, &m_var->lst_b, mark);
	print_op(m_var->op);
	/*ft_printf("lst_a :");
	print_lst(m_var->lst_a);
	ft_printf("lst_b :");
	print_lst(m_var->lst_b);*/
	ft_lstdel(&m_var->lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&m_var->lst_b, (void(*)(void*, size_t))del_content);
	free_init(m_var->tab_op);
	ft_lstdel(&m_var->op, (void(*)(void*, size_t))del_content);
	return (0);
}

int			main(int ac, char **av)
{
	t_main	m_var;
	t_mark	mark;
	int		ret;
	int		len;

	if ((ret = init_var(&m_var, ac, av)))
		return (ret);
	mark.asc = 0;
	mark.tab_op = m_var.tab_op;
	mark.op_lst = &(m_var.op);
	//ft_printf("lst_a :");
	//print_lst(m_var.lst_a);
	if ((len = ft_lstcount(m_var.lst_a)) <= 3)
		return (short_len(&m_var, &mark));
	else if (len <= 5)
		return (mid_len(&m_var, &mark));
	ulti_sort(&m_var.lst_a, &m_var.lst_b, &mark);
	print_op(m_var.op);
	/*ft_printf("lst_a :");
	print_lst(m_var.lst_a);
	ft_printf("lst_b :");
	print_lst(m_var.lst_b);*/
	ft_lstdel(&m_var.lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&m_var.lst_b, (void(*)(void*, size_t))del_content);
	free_init(m_var.tab_op);
	ft_lstdel(&m_var.op, (void(*)(void*, size_t))del_content);
	return (0);
}
