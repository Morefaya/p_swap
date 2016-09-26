#include "push_swap.h"

void	new_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int	med;
	int	f_quart;
	int	s_quart;
	int	i;
	int	k;
	int	lim_1;
	int	lim_2;
	int	len;
	int	var;

	i = 0;	
	k = 0;
	len = ft_lstcount(*lst_a);
	med = lstmed_range(*lst_a, len);
	f_quart = lst_fquart(*lst_a, len);
	s_quart = lst_squart(*lst_a, len);
	lim_1 = (len / 2) / 2 + (len / 2) % 2 + (len / 2 + len % 2) / 2;
	lim_2 = (len / 2) / 2 + (len / 2 + len % 2) / 2 + (len / 2 + len % 2) % 2;
	while (k < lim_1)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < med && var >= f_quart)
		{
			p_local(lst_a, lst_b, mark);
			k++;
		}
		else if (var >= med && var < s_quart)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
			k++;
		}
		else
		{
			r_local(lst_a, mark);
			i++;
		}
	}
	k = 0;
	while (k < lim_2)
	{	
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < f_quart)
		{
			p_local(lst_a, lst_b, mark);
			k++;
		}
		else if (var >= s_quart)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
			k++;
		}
	}
}
