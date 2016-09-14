#include "push_swap.h"

static t_list	*make_dblink(int len)
{
	t_list	*link_1;
	t_list	*link_2;
	t_pile	pile_1;
	t_pile	pile_2;

	link_1 = NULL;
	link_2 = NULL;
	pile_1.val = len / 2;
	pile_2.val = len / 2 + len % 2;
	if (!(link_1 = ft_lstnew(&pile_1, sizeof(t_pile)))
		|| !(link_2 = ft_lstnew(&pile_2, sizeof(t_pile))))
	{
		free(link_1);
		free(link_2);
		return (NULL);
	}
	ft_lstadd_back(link_1, link_2);
	return (link_1);
}

static void	make_quadlink(t_list *lst_len)
{
	int	var;
	int	len_1;
	int	len_2;
	t_list	*dble_1;
	t_list	*dble_2;

	dble_1 = NULL;
	dble_2 = NULL;
	var = ((t_pile*)(lst_len->content))->val;
	if (var < 8)
	{
		cpy_link(lst_len);
		return ;
	}
	len_1 = var / 2;
	len_2 = var / 2 + var % 2;
	if (!(dble_1 = make_dblink(len_1)) || !(dble_2 = make_dblink(len_2)))
	{
		free(dble_1);
		free(dble_2);
		return ;
	}
	ft_lstadd_back(dble_1, dble_2);
	ft_lstadd_back(lst_len, dble_1);
	return ;
}

t_list	*get_quartlstlen(int len)
{
	t_list	*lst_len;
	t_pile	data;
	t_list	*trash;

	trash = NULL;
	data.val = len;
	if (!(lst_len = ft_lstnew(&data, sizeof(t_pile))))
		return (NULL);
	while (check_lstlen(lst_len))
	{
		make_quadlink(lst_len);
		push(&lst_len, &trash);
	}
	while (trash)
		push(&trash, &lst_len);
	//ft_lstdel(&trash, (void(*)(void*, size_t))del_content);
	return (lst_len);
}
