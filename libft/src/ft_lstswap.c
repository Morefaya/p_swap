#include "libft.h"

void	ft_lstswap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	else if (!(*lst)->next)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
}
