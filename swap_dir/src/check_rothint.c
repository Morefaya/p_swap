#include "push_swap.h"

int		check_rothint(t_hint *hint, t_range rg)
{
	int 	i;
	int		len;
	int		var;
	t_list	*lst_a;

	i = 0;
	lst_a = *(hint->lst_a);
	len = ft_lstcount(lst_a);
	while (lst_a)
	{
		var = ((t_pile*)(lst_a->content))->val;
		if ((var >= rg.one && var < rg.two) || (var >= rg.three && var < rg.four))
			break;
		i++;
		lst_a = lst_a->next;
	}
	//ft_printf("len_a :%d' i :%d\n", len, i);
	if (i <= len / 2)
		return (1);
	else
		return (0);
}
