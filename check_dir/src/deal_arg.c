/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:51:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 20:32:42 by jcazako          ###   ########.fr       */
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

t_list		*deal_arg(int ac, int *opt, char **av)
{
	char	**av_cpy;
	int		*tab;
	t_list	*lst;
	int		nb_arg;

	lst = NULL;
	if (!(av_cpy = get_av_cpy(get_option(ac, opt, av), ac, &nb_arg, av)))
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(*tab) * nb_arg)))
	{
		delete_cpy(av_cpy);
		return (NULL);
	}
	if (check_nbr(nb_arg, av_cpy, tab) || !(lst = lst_inttab(tab, nb_arg)))
	{
		delete_cpy(av_cpy);
		free(tab);
		return (NULL);
	}
	free(tab);
	delete_cpy(av_cpy);
	return (lst);
}
