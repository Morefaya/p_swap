#include "push_swap.h"

void	do_op(t_list **lst, int op_num)
{
	if (!lst || !op_num)
		return ;
	else if (!*lst)
		return ;
	if (op_num == S)
		swap(lst);
	else if (op_num == R)
		rotate(lst);
	else if (op_num == REV)
		rev_rotate(lst);
}

