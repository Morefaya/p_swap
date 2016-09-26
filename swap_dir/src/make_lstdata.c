#include "push_swap.h"

t_list	*make_lstdata(t_list *lst, int itr)
{
	t_list	*lst_data;
	t_list	*tmp;
	int	pow;
	int	i;

	lst_data = NULL;
	i = 0;
	while (i++ < itr)
	{
		pow = ft_pow(2, i);
		if (!(tmp = get_lstdata(lst, pow)))
		{
			ft_lstdel(&lst_data, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		if (!lst_data)
			ft_lstadd(&lst_data, tmp);
		else
			ft_lstadd_back(lst_data, tmp);
	}
	sort_it(&lst_data);
	return (lst_data);
}
