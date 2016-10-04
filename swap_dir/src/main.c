/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 19:52:12 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**tab_op;
	t_mark	mark;
	t_list	*op_f;

	lst_a = NULL;
	lst_b = NULL;
	op_f = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);
	if (!(tab_op = init_op()))
		return (2);
	mark.tab_op = tab_op;
	mark.op_lst = &op_f;
	mark.asc = 0;
	ulti_sort(&lst_a, &lst_b, &mark);
	ft_printf("lst_a :");
	print_lst(lst_a);
	ft_printf("lst_b :");
	print_lst(lst_b);
	//print_op(op_f);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	free_init(tab_op);
	ft_lstdel(&op_f, (void(*)(void*, size_t))del_content);
	//while(42);
	return (0);
}
