/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/08 22:35:39 by jcazako          ###   ########.fr       */
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

	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);
	print_lst(lst_a);
	swap(&lst_a);
	ft_putchar('\n');
	print_lst(lst_a);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	return (0);
}
