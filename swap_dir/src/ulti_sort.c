#include "push_swap.h"

static t_list	*get_goodtr(t_list *lst, int *div)
{
	t_list	*lst_lim;
	t_tree	*tr;
	int	len;

	lst_lim = NULL;
	tr = NULL;
	len = ft_lstcount(lst);
	while (check_lstlen(lst_lim, 20))
	{
		ft_trdel(&tr, (void(*)(void*, size_t))del_content);
		ft_lstdel(&lst_lim, (void(*)(void*, size_t))del_content);
		if (!(tr = get_trlen(len, *div)))
			return (NULL);
		get_lstconf(tr, &lst_lim);
		(*div)++;
	}
	ft_trdel(&tr, (void(*)(void*, size_t))del_content);
	return (lst_lim);
}

void	ulti_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	t_list	*lst_conf;
	t_list	*lst_data;
	t_list	*lst_lim;
	int	div;
	t_hint	hint;
	
	div = 1;
	lst_conf = NULL;
	lst_lim = NULL;
	lst_conf = get_goodtr(*lst_a, &div);
	if (!(lst_data = make_lstdata(*lst_a, div - 1)))
	{
		ft_lstdel(&lst_conf, (void(*)(void*, size_t))del_content);
		return ;
	}
	lst_lim = get_lstlim(lst_conf);
	hint.lst_a = lst_a;
	hint.lst_b = lst_b;
	hint.mark = mark;
	hint.lst_data = lst_data;
	hint.lst_conf = lst_conf;
	hint.lst_lim = lst_lim;
	deal_hint(hint);
	ft_lstdel(&lst_conf, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_data, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_lim, (void(*)(void*, size_t))del_content);
}
