#include "push_swap.h"

static int	choose_nb(int len)
{
	int	tmp;
	int	nb;
	int	aux;

	aux = 7;
	tmp = len / 100;
	nb = aux + aux * tmp;
	return (nb);
}

static t_list	*get_goodtr(t_list *lst, int *div)
{
	t_list	*lst_conf;
	t_tree	*tr;
	int	len;
	int	nb;

	lst_conf = NULL;
	tr = NULL;
	len = ft_lstcount(lst);
	nb = choose_nb(len);
	while (check_lstlen(lst_conf, nb))
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
	int	div;
	t_hint	hint;
	
	div = 1;
	hint.lst_a = lst_a;
	hint.lst_b = lst_b;
	hint.mark = mark;
	lst_conf = get_goodtr(*lst_a, &div);
	if (!(hint.lst_data = make_lstdata(*lst_a, div - 1)))
		return ;
	hint.lst_conf = calc_lstconf(hint.lst_data, *hint.lst_a);
	hint.lst_lim = get_lstlim(hint.lst_conf);
	deal_hint(hint);
	sort_push(hint, hint.lst_conf);
	ft_lstdel(&lst_conf, (void(*)(void*, size_t))del_content);
	ft_lstdel(&hint.lst_conf, (void(*)(void*, size_t))del_content);
	ft_lstdel(&hint.lst_data, (void(*)(void*, size_t))del_content);
	ft_lstdel(&hint.lst_lim, (void(*)(void*, size_t))del_content);
}
