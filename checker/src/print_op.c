#include "checker.h"

void	print_op(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putendl(((t_op*)(lst->content))->op);
		lst = lst->next;
	}
}
