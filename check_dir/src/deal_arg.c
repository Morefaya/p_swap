/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:51:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 18:50:35 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	deal_option(int *opt, int *ac, char ***av)
{
	ft_printf("start deal_opt :\n");
	ft_printf("%s\n", **av);
	if ((*opt = get_option(*ac, *av)))
	{
		ft_printf("get_opt :\n");
		ft_printf("%s\n", **av);
		if (!(*ac = count_arg(*ac, av)))
		{
			ft_printf("count_arg :\n");
			ft_printf("%s\n", **av);
			return (1);
		}
	}
	else
	{
		ft_printf("else : *ac: %d\n", *ac);
		ft_printf("%s\n", **av);
		(*av)++;
		(*ac)--;
	}
	ft_printf("end :\n");
	ft_printf("%s\n", **av);
	ft_printf("end :\n");
	ft_printf("%s\n", *(*av + 1));
	return (0);
}

static char	**get_av_cpy(int *ac, char **av)
{
	char	**av_cpy;

	av_cpy = NULL;
	if (*ac == 1)
	{
		if (!(av_cpy = ft_strstr_split(av[0], " \t")))
			return (NULL);
		*ac = count_nbr_split(av_cpy);
	}
	else
	{
		if (!(av_cpy = arg_cpy(*ac, av)))
			return (NULL);
		(*ac)--;
	}
	return (av_cpy);
}

t_list		*deal_arg(int ac, int *opt, char **av)
{
	char	**av_cpy;
	int	*tab;
	t_list	*lst;

	lst = NULL;
	if (deal_option(opt, &ac, &av) || !(av_cpy = get_av_cpy(&ac, av)))
		return (NULL);
	if (!(tab = (int*)malloc(sizeof(*tab) * ac)))
	{
		delete_cpy(av_cpy);
		return (NULL);
	}
	if (check_nbr(ac, av_cpy, tab) || !(lst = lst_inttab(tab, ac)))
	{
		delete_cpy(av_cpy);
		free(tab);
		return (NULL);
	}
	free(tab);
	delete_cpy(av_cpy);
	return (lst);
}
