#include "tool.h"

int	double_val(t_list *lst, int val)
{
	while (lst)
	{
		if (((t_pile*)(lst->content))->val == val)
			return (1);
		lst = lst->next;
	}
	return (0);
}
