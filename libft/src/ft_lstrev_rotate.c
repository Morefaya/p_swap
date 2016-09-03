#include "libft.h"

void	ft_lstrev_rotate(t_list **lst)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!*lst)
		return ;
	else if (!(*lst)->next)
		return ;
	tmp_1 = *lst;
	while (tmp_1->next)
	{
		if (!tmp_1->next->next)
		{
			tmp_2 = *lst;
			*lst = tmp_1->next;
			tmp_1->next = NULL;
			(*lst)->next = tmp_2;
			break ;
		}
		tmp_1 = tmp_1->next;
	}
}
