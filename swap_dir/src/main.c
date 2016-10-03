/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/03 18:34:39 by jcazako          ###   ########.fr       */
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
	t_list	*op_f;
	t_list	*op;

	lst_a = NULL;
	lst_b = NULL;
	op_a = NULL;
	op_b = NULL;
	op_f = NULL;
	op = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);
	if (!(tab_op = init_op()))
		return (2);
	mark.tab_op = tab_op;
	mark.op_lst = &op_f;
	mark.asc = 0;
//	print_lst(lst_a);
//	ft_printf("\n");

//	int	len = ft_lstcount(lst_a);
//	supa_swap(&lst_a, &lst_b, &mark);
//	quart_sort(&lst_a, &lst_b, &mark, len);
//	new_sort(&lst_a, &lst_b, &mark);
//	oct_sort(&lst_a, &lst_b, &mark);
/*	ft_printf("lst_a:\t");
	print_lst(lst_a);
	ft_printf("lst_b:\t");
	print_lst(lst_b);
*/

	//quart_sort(&lst_b, &lst_a, &mark, len / 4);
	//lst_b = get_quartlstlen(len);
	/*int	med = lstmed_range(lst_a, len);
	int	f_quart = lst_fquart(lst_a, len);
	int	s_quart = lst_squart(lst_a, len);*/
	//quart_sort(&lst_a, &lst_b, &mark, len);
	//quart_sort(&lst_b, &lst_a, &mark, len / 2);
	//quart_sort(&lst_b, &lst_a, &mark, ft_lstcount(lst_a) / 2);
	//ft_printf("f_quart: %d, med: %d, s_quart: %d\n", f_quart, med, s_quart);
//	print_op(op_f);

	//ft_printf("\n");
	//supa_swap(&lst_a, &lst_b, &mark);
	//five_sort(&lst_a, 5);
	//len_sort(&lst_a, &mark, ft_lstcount(lst_a));
	//elem_sort(&lst_a, 3);
	//final_sort(&lst_a, &lst_b, &mark, ft_lstcount(lst_a));
	//swap_sort(&lst_a, &lst_b);
//	print_op(op_f);
//	lst_b = make_lstdata(lst_a, 8);
//	sort_it(&lst_a);
	/*ft_printf("lst_a :\n");
	print_lst(lst_a);
	ft_printf("lst_b :\n");
	print_lst(lst_b);*/
	ulti_sort(&lst_a, &lst_b, &mark);
	/*ft_printf("lst_a :");
	print_lst(lst_a);
	ft_printf("lst_b :");
	print_lst(lst_b);*/
	print_op(op_f);
	/*print_lst(lst_a);
	ft_putchar('\n');
	print_lst(lst_b);

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
	//ft_trdel(&tr, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	free_init(tab_op);
	ft_lstdel(&op_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&op_b, (void(*)(void*, size_t))del_content);
	ft_lstdel(&op, (void(*)(void*, size_t))del_content);
	//while(42);
	return (0);
}
