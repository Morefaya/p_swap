/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:51:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 22:15:15 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**get_av_cpy(int nb_opt, int ac, int *nb_arg, char **av)
{
	char	**av_cpy;

	*nb_arg = ac - nb_opt - 1;
	av_cpy = NULL;
	if (!*nb_arg)
		return (NULL);
	else if (*nb_arg == 1)
	{
		if (!(av_cpy = ft_strstr_split(av[nb_opt + 1], " \t")))
			return (NULL);
		*nb_arg = count_nbr_split(av_cpy);
	}
	else if (!(av_cpy = arg_cpy(*nb_arg, av + nb_opt + 1)))
		return (NULL);
	return (av_cpy);
}

static int	init_arg(t_darg *arg, int ac, int *opt, char **av)
{
	arg->lst = NULL;
	arg->nb_opt = get_option(ac, opt, av);
	if (!(arg->av_cpy = get_av_cpy(arg->nb_opt, ac, &(arg->nb_arg), av)))
		return (1);
	if (arg->nb_opt)
	{
		delete_cpy(arg->av_cpy);
		puterror(0);
		return (2);
	}
	return (0);
}

t_list		*deal_arg(int ac, int *opt, char **av)
{
	t_darg	arg;

	if (init_arg(&arg, ac, opt, av))
		return (NULL);
	if (!(arg.tab = (int*)malloc(sizeof(*(arg.tab)) * arg.nb_arg)))
	{
		delete_cpy(arg.av_cpy);
		return (NULL);
	}
	if (check_nbr(arg.nb_arg, arg.av_cpy, arg.tab)
		|| !(arg.lst = lst_inttab(arg.tab, arg.nb_arg)))
	{
		delete_cpy(arg.av_cpy);
		free(arg.tab);
		return (NULL);
	}
	free(arg.tab);
	delete_cpy(arg.av_cpy);
	return (arg.lst);
}
