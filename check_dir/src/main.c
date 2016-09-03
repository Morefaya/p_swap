/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:32:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/09/01 21:05:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		puterror(int ret)
{
	ft_putendl_fd("Error", 2);
	return (ret);
}

static void	print_result(t_list *lst_a, t_list *lst_b)
{
	if (check_asc(lst_a) == 1 && !lst_b)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int	opt;

	lst_b = NULL;
	if (ac == 1)
		return (0);
	if (!(lst_a = deal_arg(ac, &opt, av)))
		return (1);
	deal_op(opt, &lst_a, &lst_b);
	print_result(lst_a, lst_b);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	return (0);
}
