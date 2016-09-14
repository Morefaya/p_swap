#include "push_swap.h"

int	quart_sort(t_list **lst_a, t_list **lst_b, t_mark *mark, int range)
{
	int	med;
	int	f_quart;
	int	s_quart;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	med = lstmed_range(*lst_a, range);
	f_quart = lst_fquart(*lst_a, range);
	s_quart = lst_squart(*lst_a, range);
	//print_lst(*lst_a);
	//ft_printf("f_quart: %d, med: %d, s_quart: %d, range: %d\n", f_quart, med, s_quart, range);
	while (k < range / 2)
	{
		if (((t_pile*)((*lst_a)->content))->val < med)
		{
			mark->asc = 0;
			if (((t_pile*)((*lst_a)->content))->val >= f_quart)
			{
				p_local(lst_a, lst_b, mark);
				j++;
			}
			else
			{
				p_local(lst_a, lst_b, mark);
				r_local(lst_b, mark);
			}
			mark->asc = 1;
			k++;
		}
		else
		{
			r_local(lst_a, mark);
			i++;
		}
	}
	while (i--)
		rev_local(lst_a, mark);
	mark->asc = 0;
	while (j--)
		r_local(lst_b, mark);
	i = 0;
	j = 0;
	while (i++ < range / 2 + range % 2)
	{
		if (((t_pile*)((*lst_a)->content))->val < s_quart)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
		}
		else
		{
			p_local(lst_a, lst_b, mark);
			j++;
		}
	}
	while (j--)
		r_local(lst_b, mark);
	mark->asc = 1;
	/*ft_printf("lst_a\n");
	print_lst(*lst_a);
	ft_printf("lst_b\n");
	print_lst(*lst_b);*/
	return (range);
}
