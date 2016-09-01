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

int			puterror(int *tab, int ret)
{
	free(tab);
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

static void	check(int opt, t_list **lst_a, t_list **lst_b)
{
	t_list	*op_lst;

	op_lst = NULL;
	if (!opt)
	{
		if (!(op_lst = get_op_lst()))
			return ;
		do_allop(lst_a, lst_b, &op_lst);
		ft_lstdel(&op_lst, (void(*)(void*, size_t))del_op);
	}
	else if (opt & OPT_A)
		do_op(lst_a, lst_b);
}

int			main(int ac, char **av)
{
	int		*tab;
	t_list	*lst_a;
	t_list	*lst_b;
	int		opt;

	lst_b = NULL;
	if (ac == 1)
		return (0);
	if ((opt = get_option(ac, av)))
		ac = count_arg(ac, &av);
	if (!(tab = (int*)malloc(sizeof(*tab) * (ac - 1))))
		return (1);
	if (check_nbr(ac, av, tab) || !(lst_a = lst_inttab(tab, ac - 1)))
	{
		free(tab);
		return (3);
	}
	check(opt, &lst_a, &lst_b);
	print_result(lst_a, lst_b);
	free(tab);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	return (0);
}
