#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*trash;

	trash = NULL;
	while (*lst)
	{
		ft_lstrev_rotate(lst);
		ft_lstpush(lst, &trash);
	}
	while (trash)
		ft_lstpush(&trash, lst);
}
