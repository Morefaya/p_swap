/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/20 19:33:34 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**tab_op;
	t_mark	mark;
	t_list	*op_a;
	t_list	*op_b;
	t_list	*op;

	lst_a = NULL;
	lst_b = NULL;
	op_a = NULL;
	op_b = NULL;
	op = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);
	if (!(tab_op = init_op()))
		return (2);
	print_lst(lst_a);
	ft_printf("\n");

	mark.tab_op = tab_op;
	mark.op_lst = &op;
	mark.asc = 1;
	supa_swap(&lst_a, &lst_b, &mark);
	/*int	i = 0;
	int	ret;
	int	j;
	int	len = ft_lstcount(lst_a);
	while (i < len)
	{
		j = 0;
		ret = test_sort(&lst_a, &lst_b, ft_lstcount(lst_a) - i);
		while (j++ < ret)
			rotate(&lst_a);
		i += ret;
	}*/
	//five_sort(&lst_a, 5);
	//elem_sort(&lst_a, 3);
	//final_sort(&lst_a, &lst_b, 6);
	//swap_sort(&lst_a, &lst_b);
	ft_printf("lst_a:\n");
	print_lst(lst_a);
	ft_printf("lst_b:\n");
	print_lst(lst_b);
	ft_printf("\n");
	//print_op(op);
	/*print_lst(lst_a);
	ft_putchar('\n');

	mark.tab_op = tab_op;
	mark.op_lst = &op_a;
	mark.asc = 0;
	quick_sort(&lst_a, &lst_b, &mark);
	

	print_lst(lst_a);
	ft_putchar('\n');
	print_lst(lst_b);
	ft_putchar('\n');
	mark.tab_op = tab_op;
	mark.op_lst = &op_a;
	jc_sort(&lst_a, 1, &mark);
	mark.op_lst = &op_b;
	jc_sort(&lst_b, 0, &mark);

	mark.tab_op = tab_op;
	mark.op_lst = &op_a;
	range_sort_asc(&lst_a, 1, &mark);
	mark.op_lst = &op_b;
	range_sort_dsc(&lst_b, 0, &mark);
	
	mark.tab_op = tab_op;
	mark.op_lst = &op_a;
	mark.asc = 1;
	turn_list(&lst_a, &mark);
	mark.op_lst = &op_b;
	mark.asc = 0;
	turn_list(&lst_b, &mark);

	check_op(&op_a);
	check_op(&op_b);

	fusion_sort(&op, op_a, op_b, tab_op);

	mark.op_lst = &op;
	mark.asc = 1;
	while (lst_b)
		p_local(&lst_b, &lst_a, &mark);
	print_op(op);
	ft_printf("\n");
	print_lst(lst_a);
	print_lst(lst_b);*/
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	free_init(tab_op);
	ft_lstdel(&op_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&op_b, (void(*)(void*, size_t))del_content);
	ft_lstdel(&op, (void(*)(void*, size_t))del_content);
	return (0);
}
