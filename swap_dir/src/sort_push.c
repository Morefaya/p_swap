#include "push_swap.h"

static t_list	*cpy_len(t_list *lst, int len)
{
	t_list	*cpy_sort;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(cpy_sort = ft_lstnew(lst->content, sizeof(t_pile))))
		return (NULL);
	lst = lst->next;
	while (lst && len-- > 1)
	{
		tmp = ft_lstnew(lst->content, sizeof(t_pile));
		ft_lstadd_back(cpy_sort, tmp);
		lst = lst->next;
	}
	return (cpy_sort);
}

static int	seek_way(t_list *lst, int var)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_1 = NULL;
	tmp_2 = NULL;
	if (!(tmp_1 = ft_lstcpy(lst, sizeof(t_pile)))
		|| !(tmp_2 = ft_lstcpy(lst, sizeof(t_pile))))
	{
		ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
		ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
		return (0);
	}
	len = ft_lstcount(lst);
	while (i < len)
	{
		if (((t_pile*)(tmp_1->content))->val == var)
			break;
		rotate(&tmp_1);
		i++;
	}
	while (j < len)
	{
		if (((t_pile*)(tmp_2->content))->val == var)
			break;
		rev_rotate(&tmp_2);
		j++;
	}
	ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
	ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
	if (i <= j)
		return (i);
	else
		return (-1 * j);
}

static void	deal_sort(t_list **lst_1, t_list **lst_2, t_list *cpy_s)
{
	int		val;
	int		tmp;
	int		high;

	if (cpy_s->next)
		deal_sort(lst_1, lst_2, cpy_s->next);
	val = ((t_pile*)((*lst_1)->content))->val;
	high = ((t_pile*)(cpy_s->content))->val;
	//ft_printf("high = %d\n", high);
	if (val == high)
	{
		push(lst_1, lst_2);
		/*ft_printf("lst_1 \n");
		print_lst(*lst_1);
		ft_printf("lst_2 \n");
		print_lst(*lst_2);*/
	}
	else if ((tmp = seek_way(*lst_1, high)) > 0)
	{
		while (tmp--)
			rotate(lst_1);
		push(lst_1, lst_2);
		/*ft_printf("lst_1 \n");
		print_lst(*lst_1);
		ft_printf("lst_2 \n");
		print_lst(*lst_2);*/
	}
	else
	{
		while (tmp++)
			rev_rotate(lst_1);
		/*ft_printf("lst_1 \n");
		print_lst(*lst_1);
		ft_printf("lst_2 \n");
		print_lst(*lst_2);*/
		push(lst_1, lst_2);
	}
}

void	sort_push(t_list **lst_1, t_list **lst_2, t_list *lst_conf)
{
	int		len;
	t_list	*cpy_s;

	//ft_printf("lst_conf: ");
	//print_lst(lst_conf);
	if (lst_conf->next)
		sort_push(lst_1, lst_2, lst_conf->next);
	cpy_s = NULL;
	len = ((t_pile*)(lst_conf->content))->val;
	if (!(cpy_s = cpy_len(*lst_1, len)))
		return ;
	sort_it(&cpy_s);
	deal_sort(lst_1, lst_2, cpy_s);
	ft_lstdel(&cpy_s, (void(*)(void*, size_t))del_content);
	/*cpy_s = NULL;
	while (lst_conf)
	{
		ft_lstdel(&cpy_s, (void(*)(void*, size_t))del_content);
		len = ((t_pile*)(lst_conf->content))->val;
		if (!(cpy_s = cpy_len(*lst_1, len)))
			return ;
		sort_it(&cpy_s);
		deal_sort(lst_1, lst_2, cpy_s);
		lst_conf = lst_conf->next;
	}*/
		/*ft_printf("cpy_s: ");
		print_lst(cpy_s);
		ft_printf("lst_1 :");
		print_lst(*lst_1);
		ft_printf("lst_2 :");
		print_lst(*lst_2);
		ft_printf("\n");*/
}
