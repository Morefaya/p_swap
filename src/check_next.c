#include "push_swap.h"

int		check_next(t_list *lst)
{
	if (!lst)
		return (-1);
	if (((t_pile*)(lst->content))->val > ((t_pile*)(lst->next->content))->val)
		return (1);
	else
		return (0);
}
