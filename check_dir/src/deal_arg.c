#include "checker.h"

static int	deal_option(int *opt, int *ac, char ***av)
{
	if ((*opt = get_option(*ac, *av)))
	{
		if (!(*ac = count_arg(*ac, av)))
			return (1);
	}
	else
	{
		(*av)++;
		(*ac)--;
	}
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
