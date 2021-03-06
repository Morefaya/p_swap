#include "push_swap.h"

void	get_lstconf(t_tree *tr, t_list **lst)
{
	t_pile	data;
	t_list	*tmp;

	if (!tr)
		return ;
	if (!tr->left && !tr->right)
	{
		data.val = ((t_pile*)(tr->content))->val;
		if (!(tmp = ft_lstnew(&data, sizeof(t_pile))))
			return ;
		if (!*lst)
			ft_lstadd(lst, tmp);
		else
			ft_lstadd_back(*lst, tmp);
	}
	get_lstconf(tr->left, lst);
	get_lstconf(tr->right, lst);
}
