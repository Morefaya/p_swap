#include "push_swap.h"

static int	get_limit_1(int len)
{
	int	tmp;
	int	long_1;
	int	long_2;

	tmp = (len / 2) / 2 + (len / 2) % 2;
	long_1 = tmp / 2 + tmp % 2;
	long_2 = (len / 2 + len % 2) / 4;
	return (long_1 + long_2);
}

static int	get_limit_2(int len)
{
	int	tmp_1;
	int	tmp_2;
	int	long_1;
	int	long_2;
	
	tmp_1 = (len / 2) / 2 + (len / 2) % 2;
	long_1 = tmp_1 / 2;
	tmp_2 = (len / 2 + len % 2) / 2;
	long_2 = tmp_2 / 2 + tmp_2 % 2;
	return (long_1 + long_2);
}

static int	get_limit_3(int len)
{
	int	long_1;
	int	long_2;

	long_1 = (len / 8)  + (len / 4) % 2;
	long_2 = (len / 2 + len % 2) / 4 + (len / 2 + len % 2) % 2 / 2;
	return (long_1 + long_2);
}

static int	get_limit_4(int len)
{
	int	tmp;
	int	long_1;
	int	long_2;

	long_1 = (len / 8);
	tmp = (len / 2 + len % 2) / 2 + (len / 2 + len % 2) % 2;
	long_2 = tmp / 2 + tmp % 2;
	return (long_1 + long_2);
}

void	oct_sort(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int	med;
	int	f_quart;
	int	s_quart;
	int	oct_1;
	int	oct_2;
	int	oct_3;
	int	oct_4;
	int	len;
	int	var;
	int	lim_1;
	int	lim_2;
	int	lim_3;
	int	lim_4;
	int	i;

	len = ft_lstcount(*lst_a);
	med = lstmed_range(*lst_a, len);
	f_quart = lst_fquart(*lst_a, len);
	s_quart = lst_squart(*lst_a, len);
	oct_1 = lst_oct_1(*lst_a, len);
	oct_2 = lst_oct_2(*lst_a, len);
	oct_3 = lst_oct_3(*lst_a, len);
	oct_4 = lst_oct_4(*lst_a, len);
	lim_1 = get_limit_1(len);
	lim_2 = get_limit_2(len);
	lim_3 = get_limit_3(len);
	lim_4 = get_limit_4(len);
	i = 0;	
	while (i < lim_1)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < med && var >= oct_2)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else if (var >= med && var < oct_3)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
			i++;
		}
		else
			r_local(lst_a, mark);
	}
	i = 0;
	while (i < lim_2)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < oct_2 && var >= f_quart)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else if (var >= oct_3 && var < s_quart)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
			i++;
		}
		else
			r_local(lst_a, mark);
	}
	i = 0;
	while (i < lim_3)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < f_quart && var >= oct_1)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else if (var >= s_quart && var < oct_4)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
			i++;
		}
		else
			r_local(lst_a, mark);
	}
	i = 0;
	while (i < lim_4)
	{
		var = ((t_pile*)((*lst_a)->content))->val;
		if (var < oct_1)
		{
			p_local(lst_a, lst_b, mark);
			i++;
		}
		else if (var >= oct_4)
		{
			p_local(lst_a, lst_b, mark);
			r_local(lst_b, mark);
			i++;
		}
		else
			r_local(lst_a, mark);
	}
}
