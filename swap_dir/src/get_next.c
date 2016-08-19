#include "push_swap.h"

int	get_next(t_list *lst)
{
	if (!lst)
		return (0);
	else if (!lst->next)
		return (0);
	return (((t_pile*)(lst->next->content))->val);
}
