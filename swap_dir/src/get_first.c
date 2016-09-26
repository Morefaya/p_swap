#include "push_swap.h"

int	get_first(t_list *lst)
{
	if (!lst)
		return (0);
	return (((t_pile*)(lst->content))->val);
}
