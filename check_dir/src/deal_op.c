#include "checker.h"

void	deal_op(int opt, t_list **lst_a, t_list **lst_b)
{
	t_list	*op_lst;

	op_lst = NULL;
	if (!opt)
	{
		if (!(op_lst = get_op_lst()))
			return ;
		do_allop(lst_a, lst_b, &op_lst);
		ft_lstdel(&op_lst, (void(*)(void*, size_t))del_op);
	}
	else if (opt & OPT_A)
	{
		print_lst(*lst_a);
		ft_putchar('\n');
		do_op(lst_a, lst_b);
	}
}
