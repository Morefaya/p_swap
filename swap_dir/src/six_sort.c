#include "push_swap.h"

/*static void	fusion(t_list **op, t_mark *mark)
{
	
}*/

void		six_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int	var;
	int	med;
	int	len;
	int	i;
	
	med = lst_median(*lst_a);
	len = ft_lstcount(*lst_a);
	i = 0;
	while (i < len / 2)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < med)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else
		{
			mark->asc = 1;
			r_local(lst_a, mark);
			mark->asc = 0;
		}
	}
	mark->asc = 1;
	elem_sort(lst_a, mark, ft_lstcount(*lst_a));
	mark->asc = 0;
	if (!check_next(*lst_b))
		s_local(lst_b, mark);
	while (*lst_b)
	{
		mark->asc = 1;
		p_local(lst_b, lst_a, mark);
		mark->asc = 0;
	}
	ft_printf("six_sort:\nlst_a :");
	print_lst(*lst_a);
	ft_lstdel_range(lst_a, 2, del_content);
	ft_printf("before del:\nlst_a :");
	print_lst(*lst_a);
	//fusion(&(mark->op), mark);
}
