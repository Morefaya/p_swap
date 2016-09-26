#include "push_swap.h"

int	get_lstval(t_list *lst, int range)
{
	while (lst && range--)
		lst = lst->next;
	return (((t_pile*)(lst->content))->val);
}
