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

	lst_a = NULL;
	lst_b = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);

	/*print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');*/
	quick_sort(&lst_a, &lst_b);

	jc_sort(&lst_a, 1);
	jc_sort(&lst_b, 0);

	print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');
	range_sort_asc(&lst_a);
	range_sort_dsc(&lst_b);
	turn_list(&lst_a);
	turn_list(&lst_b);
	while (lst_b)
		push(&lst_b, &lst_a);
	print_lst(lst_a);
	print_lst(lst_b);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	return (0);
}
