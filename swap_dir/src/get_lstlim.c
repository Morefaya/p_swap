#include "push_swap.h"

static t_list	*make_lstlim(t_list *lst, int low, int high)
{
	t_list	*lst_lim;
	t_pile	data;
	t_list	*tmp;
	
	lst_lim = NULL;
	while (low >= 0 && high < ft_lstcount(lst))
	{
		data.val = get_lstval(lst, low) + get_lstval(lst, high);
		if (!(tmp = ft_lstnew(&data, sizeof(t_pile))))
		{
			ft_lstdel(&lst, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		if (!lst_lim)
			ft_lstadd(&lst_lim, tmp);
		else
			ft_lstadd_back(lst_lim, tmp);
		low--;
		high++;
	}
	return (lst_lim);
}

t_list	*get_lstlim(t_list *lst)
{
	//t_tree	*tr;
	//t_list	*lst;
	t_list	*lst_lim;
	int	len;

	/*lst = NULL;
	if (!(tr = get_trlen(len, div)))
		return (NULL);
	get_lstconf(tr, &lst);
	if (!lst)
	{
		ft_trdel(&tr, (void(*)(void*, size_t))del_content);
		return (NULL);
	}*/
	len = ft_lstcount(lst);
	//ft_printf("len :%d\n", len);
	lst_lim = make_lstlim(lst, len / 2 - 1, len / 2);
	//ft_lstdel(&lst, (void(*)(void*, size_t))del_content);
	//ft_trdel(&tr, (void(*)(void*, size_t))del_content);
	return (lst_lim);
}
