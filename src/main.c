/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 21:41:36 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_content(t_pile *content, size_t size)
{
	ft_bzero(content, size);
	free(content);
}

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);

	//print_lst(lst_a);
	//print_lst(lst_b);

	quick_sort(&lst_a, &lst_b);
	//ft_putnbr(check_asc(lst_a));
	//print_lst(lst_a);
	//print_lst(lst_b);

	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	return (0);
}
