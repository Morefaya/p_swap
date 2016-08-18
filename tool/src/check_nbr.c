#include "tool.h"

static t_list	*puterror(t_list **lst)
{
	ft_lstdel(lst, (void(*)(void*, size_t))del_content);
	ft_putendl_fd("Error", 2);
	return (NULL);
}

static t_list	*listing_nbr(t_list **nbr_lst, int ac, char **av)
{
	int	i;
	t_pile	data;
	t_list	*tmp;

	i = 1;
	while (++i < ac)
	{
		if (!strisnbr(av[i]))
			return (puterror(nbr_lst));
		data.val = ft_atoi(av[i]);
		if (double_val(*nbr_lst, data.val) || max_int(data.val, av[i]))
			return (puterror(nbr_lst));
		if (!(tmp = ft_lstnew(&data, sizeof(data))))
		{
			ft_lstdel(nbr_lst, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		ft_lstadd_back(*nbr_lst, tmp);
	}
	return (*nbr_lst);
}

t_list		*check_nbr(int ac, char **av)
{
	t_list	*nbr_lst;
	t_pile	data;

	if (!strisnbr(av[1]))
		return (puterror(NULL));
	data.val = ft_atoi(av[1]);
	if (!(nbr_lst = ft_lstnew(&data, sizeof(data))))
		return (NULL);
	return (listing_nbr(&nbr_lst, ac, av));
}
