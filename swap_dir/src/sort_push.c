#include "push_swap.h"

static t_list	*cpy_len(t_list *lst, int len)
{
	t_list	*cpy_sort;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(cpy_sort = ft_lstnew(lst->content), sizeof(t_pile)))
		return (NULL);
	lst = lst->next;
	while (lst && len--)
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
	len = ft_lstcount(tmp);
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
	if (i <= j)
		return (i);
	else
		return (-1 * j);
}

static void	deal_sort(t_list **lst_1, t_list **lst_2, int len, t_list *cpy_s)
{
	int		val;
	int		tmp;
	int		high;

	while (cpy_s)
	{
		val = ((t_pile*)(*(lst_1)->content))->val;
		high = ((t_pile*)(cpy_s->content))->val;
		if (val == hight)
			push(lst_1, lst_2);
		else if ((tmp = seek_way(*lst_1), high) > 0)
		{
			while (tmp--)
				rotate(lst_1);
		}
		else
		{
			while (tmp++)
				rev_rotate(lst_2);
		}
		cpy_s = cpy_s->next;
	}	
}

void	sort_push(t_list **lst_1, t_list **lst_2, t_list *lst_conf)
{
	int		high;
	int		len;
	t_list	*cpy_s;

	while (lst_conf)
	{
		len = ((t_pile*)(lst_conf->content))->val;
		if (!(cpy_s = cpy_len(*lst_1, len)))
			return ;
		sort_it(&cpy_sort);
		deal_sort(lst_1, lst_2, len, cpy_s);
		lst_conf = lst_conf->next;
	}
}
