#include "push_swap.h"

void	print_op(t_list *lst)
{
	while (lst)
	{
		ft_putendl(((t_op*)(lst->content))->op);
		lst = lst->next;
	}
}
