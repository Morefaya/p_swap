#include "push_swap.h"

static t_list	*get_goodtr(t_list *lst, int *div)
{
	t_list	*lst_conf;
	t_tree	*tr;
	int	len;

	lst_conf = NULL;
	tr = NULL;
	len = ft_lstcount(lst);
	while (check_lstlen(lst_conf, 7)) //(*div < 4)
	{
		ft_trdel(&tr, (void(*)(void*, size_t))del_content);
		ft_lstdel(&lst_conf, (void(*)(void*, size_t))del_content);
		if (!(tr = get_trlen(len, *div)))
			return (NULL);
		get_lstconf(tr, &lst_conf);
		(*div)++;
	}
	ft_trdel(&tr, (void(*)(void*, size_t))del_content);
	return (lst_conf);
}

void	ulti_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	t_list	*lst_conf;
	int		div;
	t_hint	hint;
	
	div = 1;
	hint.lst_a = lst_a;
	hint.lst_b = lst_b;
	hint.mark = mark;
	lst_conf = get_goodtr(*lst_a, &div);
	//ft_printf("original lst_a :\n");
	//print_lst(*hint.lst_a);
	if (!(hint.lst_data = make_lstdata(*lst_a, div - 1)))
		return ;
	hint.lst_conf = calc_lstconf(hint.lst_data, *hint.lst_a);
	hint.lst_lim = get_lstlim(hint.lst_conf);
	deal_hint(hint);
	/*ft_printf("\n\nresultat :\nlst_a: \n");
	print_lst(*hint.lst_a);
	ft_printf("lst_b :\n");
	print_lst(*hint.lst_b);*/
	ft_lstdel(&lst_conf, (void(*)(void*, size_t))del_content);
	ft_lstdel(&hint.lst_conf, (void(*)(void*, size_t))del_content);
	ft_lstdel(&hint.lst_data, (void(*)(void*, size_t))del_content);
	ft_lstdel(&hint.lst_lim, (void(*)(void*, size_t))del_content);
}
