#include "push_swap.h"

static int	ascending(t_list *lst, int len)
{
	while (lst->next && len--)
	{
		if (((t_pile*)(lst->content))->val\
				<= ((t_pile*)(lst->next->content))->val)
			return (0);
		lst = lst->next;
	}
	return (-1);
}

static int	descending(t_list *lst, int len)
{
	while (lst->next && len--)
	{
		if (((t_pile*)(lst->content))->val\
				>= ((t_pile*)(lst->next->content))->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int			check_asc_len(t_list *lst, int len)
{
	if (!lst)
		return (0);
	else if (!lst->next)
		return (1);
	if (((t_pile*)(lst->content))->val > ((t_pile*)(lst->next->content))->val)
		return (ascending(lst, len));
	else
		return (descending(lst, len));
}
