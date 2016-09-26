#include "push_swap.h"

static void	make_link(t_tree *tr, int itr)
{
	int	var;
	t_pile	data;
	t_tree	*tmp;

	if (!itr)
		return ;
	var = ((t_pile*)(tr->content))->val;
	data.val = var / 2;
	if (!(tmp = ft_trnew(&data, sizeof(t_pile))))
		return ;
	tr->left = tmp;
	data.val = var / 2 + var % 2;
	if (!(tmp = ft_trnew(&data, sizeof(t_pile))))
		return ;
	tr->right = tmp;
	make_link(tr->left, itr - 1);
	make_link(tr->right, itr - 1);
}

t_tree	*get_trlen(int len, int div)
{
	t_pile	data;
	t_tree	*tr;

	data.val = len;
	if (!(tr = ft_trnew(&data, sizeof(t_pile))))
		return (NULL);
	make_link(tr, div);
	return (tr);
}
