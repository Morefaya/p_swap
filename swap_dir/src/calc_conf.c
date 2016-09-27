#include "push_swap.h"

static int	count_below(t_list *lst_a, int val)
{
	int	i;

	i = 0;
	while (lst_a)
	{
		if (((t_pile*)(lst_a->content))->val < val)
			i++;
		lst_a = lst_a->next;
	}
	return (i);
}

static int	count_above(t_list *lst_a, int val)
{
	int	i;

	i = 0;
	while (lst_a)
	{
		if (((t_pile*)(lst_a->content))->val >= val)
			i++;
		lst_a = lst_a->next;
	}
	return (i);
}

static int	count_btw(t_list *lst_a, int one, int two)
{
	int	i;
	int	val;

	i = 0;
	while (lst_a)
	{
		val = ((t_pile*)(lst_a->content))->val;
		if (val >= one && val < two)
			i++;
		lst_a = lst_a->next;
	}
	return (i);	
}

static t_list	*deal_lstconf(t_list *lst_d, t_list *lst_a, t_list **lst_c)
{
	int		one;
	int		two;
	t_list	*tmp;
	t_pile	ct;

	one = ((t_pile*)(lst_d->content))->val;
	two = ((t_pile*)(lst_d->next->content))->val;
	ct.val = count_btw(lst_a, one, two);
	if (!(tmp = ft_lstnew(&ct, sizeof(t_pile))))
	{
		ft_lstdel(lst_c, (void(*)(void*, size_t))del_content);
		return (NULL);
	}
	ft_lstadd_back(*lst_c, tmp);
	return (*lst_c);
}

static t_list	*last_lstconf(t_list *lst_a, t_list **lst_c, int val)
{
	t_list	*tmp;
	t_pile	ct;

	ct.val = count_above(lst_a, val);
	if (!(tmp = ft_lstnew(&ct, sizeof(t_pile))))
	{	
		ft_lstdel(lst_c, (void(*)(void*, size_t))del_content);
		return (NULL);
	}
	ft_lstadd_back(*lst_c, tmp);
	return (*lst_c);
}

t_list	*calc_lstconf(t_list *lst_data, t_list *lst_a)
{
	t_list	*lst_conf;
	t_pile	content;
	int		i;
	int		len_d;

	content.val = count_below(lst_a, ((t_pile*)(lst_data->content))->val);
	if (!(lst_conf = ft_lstnew(&content, sizeof(t_pile))))
		return (NULL);
	len_d = ft_lstcount(lst_data);
	i = 0;
	while (i++ < len_d - 1)
	{
		if (!(deal_lstconf(lst_data, lst_a, &lst_conf)))
			return (NULL);
		lst_data = lst_data->next;
	}
	if (!(last_lstconf(lst_a, &lst_conf, ((t_pile*)(lst_data->content))->val)))
		return (NULL);
	return (lst_conf);
}
