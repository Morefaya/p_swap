#include "push_swap.h"

void	print_tr(t_tree *tr)
{
	if (!tr)
		return ;
	ft_printf("%d\n", ((t_pile*)(tr->content))->val);
	print_tr(tr->left);
	print_tr(tr->right);
}
