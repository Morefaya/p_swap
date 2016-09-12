#include "push_swap.h"

int	check_half_sort(t_list *lst, int len)
{
	int	med;
	int	i;
	//t_list	*lst_cpy;

	if (len > ft_lstcount(lst))
		return (0);
	//else if (!(lst_cpy = ft_lstcpy(lst, sizeof(t_pile))))
	//	return (0);
	med = lstmed_range(lst, len);
	i = 0;
	while (i++ <= len / 2)
	{
		if (((t_pile*)(lst->content))->val > med)
			return (1);
		lst = lst->next;
	}
	while (i++ < len)
	{
		if (((t_pile*)(lst->content))->val <= med)
			return (1);
		lst = lst->next;
	}
	//ft_lstdel(&lst_cpy, (void(*)(void*, size_t))del_content);
	return (0);
}
