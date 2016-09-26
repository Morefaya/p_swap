#include "push_swap.h"

int	get_last(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (((t_pile*)(lst->content))->val);
}
