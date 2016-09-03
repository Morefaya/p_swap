#include "libft.h"

void	ft_lstrotate(t_list **lst)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!*lst)
		return ;
	else if (!(*lst)->next)
		return ;
	tmp_1 = *lst;
	*lst = (*lst)->next;
	tmp_1->next = NULL;
	tmp_2 = *lst;
	while (tmp_2->next)
		tmp_2 = tmp_2->next;
	tmp_2->next = tmp_1;
}
