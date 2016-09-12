#include "push_swap.h"

int	check_lstlen(t_list *lst)
{
	while (lst)
	{
		if (((t_pile*)(lst->content))->val > 25)
			return (1);
		lst = lst->next;
	}
	return (0);
}
