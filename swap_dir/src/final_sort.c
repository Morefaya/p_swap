#include "push_swap.h"

void	final_sort(t_list **lst_a, t_list **lst_b, t_mark *mark, int len)
{
	int	med;
	int	i;
	int	k;

	if (len > ft_lstcount(*lst_a))
		return ;
	else if (!check_half_sort(*lst_a, len))
	{
		while (len--)
			rotate(lst_a);
	//	print_lst(*lst_a);
		return ;
	}
	med = lstmed_range(*lst_a, len);
	i = 0;
	k = 0;
	while (k < len / 2) //while (i + k < len)
	{
		if (((t_pile*)((*lst_a)->content))->val >= med)
		{
			mark->asc = 0;
			p_local(lst_a, lst_b, mark);
			mark->asc = 1;
			//i++;
		}
		else
		{
			r_local(lst_a, mark);
			k++;
		}
	}
	/*while (k--)
		rev_local(lst_a, mark);*/
	//k = i;
	while (*lst_b)
		p_local(lst_b, lst_a, mark);
	while (i++ < len / 2 + len % 2)  //while (i++ < k - 1)
		r_local(lst_a, mark);
	//print_lst(*lst_a);
}
