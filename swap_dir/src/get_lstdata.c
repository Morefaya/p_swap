#include "push_swap.h"

static int	lstdata(t_list *lst, int range, int i, int pow)
{
	t_lstmed	tmp;
	if (!lst)
		return (0);
	tmp.j = 0;
	tmp.nu_med = ((t_pile*)(lst->content))->val;
	tmp.tmp_1 = lst;
	while (tmp.tmp_1 && (tmp.j)++ < range)
	{
		tmp.tmp_2 = lst;
		tmp.i = 0;
		tmp.k = 0;
		while (tmp.tmp_2 && tmp.k++ < range)
		{
			if (((t_pile*)(tmp.tmp_2->content))->val\
				< ((t_pile*)(tmp.tmp_1->content))->val)
				(tmp.i)++;
			tmp.tmp_2 = tmp.tmp_2->next;
		}
		if (tmp.i == i * range / pow)
			tmp.nu_med = ((t_pile*)(tmp.tmp_1->content))->val;
		tmp.tmp_1 = tmp.tmp_1->next;
	}
	return (tmp.nu_med);
}

t_list	*get_lstdata(t_list *lst, int pow)
{
	t_list	*data;
	t_list	*tmp;
	t_pile	content;
	int	i;

	i = 1;
	data = NULL;
	while (i < pow)
	{
		content.val = lstdata(lst, ft_lstcount(lst), i, pow);
		if (!(tmp = ft_lstnew(&content, sizeof(t_pile))))
		{
			ft_lstdel(&data, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		if (!data)
			ft_lstadd(&data, tmp);
		else
			ft_lstadd_back(data, tmp);
		i += 2;
	}
	return (data);
}
