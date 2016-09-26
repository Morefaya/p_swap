#include "push_swap.h"

int		lst_oct_1(t_list *lst, int range)
{
	t_lstmed	tmp;

	if (!lst)
		return (0);
	tmp.j = 0;
	tmp.nu_med = ((t_pile*)(lst->content))->val;
	tmp.tmp_1 = lst;
	while (tmp.tmp_1 && (tmp.j)++ < range)
	{
		tmp.tmp_2 = lst;
		tmp.i = 0;
		tmp.k = 0;
		while (tmp.tmp_2 && tmp.k++ < range)
		{
			if (((t_pile*)(tmp.tmp_2->content))->val\
				< ((t_pile*)(tmp.tmp_1->content))->val)
				(tmp.i)++;
			tmp.tmp_2 = tmp.tmp_2->next;
		}
		if (tmp.i == range / 8)
			tmp.nu_med = ((t_pile*)(tmp.tmp_1->content))->val;
		tmp.tmp_1 = tmp.tmp_1->next;
	}
	return (tmp.nu_med);
}

int		lst_oct_2(t_list *lst, int range)
{
	t_lstmed	tmp;

	if (!lst)
		return (0);
	tmp.j = 0;
	tmp.nu_med = ((t_pile*)(lst->content))->val;
	tmp.tmp_1 = lst;
	while (tmp.tmp_1 && (tmp.j)++ < range)
	{
		tmp.tmp_2 = lst;
		tmp.i = 0;
		tmp.k = 0;
		while (tmp.tmp_2 && tmp.k++ < range)
		{
			if (((t_pile*)(tmp.tmp_2->content))->val\
				< ((t_pile*)(tmp.tmp_1->content))->val)
				(tmp.i)++;
			tmp.tmp_2 = tmp.tmp_2->next;
		}
		if (tmp.i == 3 * range / 8)
			tmp.nu_med = ((t_pile*)(tmp.tmp_1->content))->val;
		tmp.tmp_1 = tmp.tmp_1->next;
	}
	return (tmp.nu_med);
}


int		lst_oct_3(t_list *lst, int range)
{
	t_lstmed	tmp;

	if (!lst)
		return (0);
	tmp.j = 0;
	tmp.nu_med = ((t_pile*)(lst->content))->val;
	tmp.tmp_1 = lst;
	while (tmp.tmp_1 && (tmp.j)++ < range)
	{
		tmp.tmp_2 = lst;
		tmp.i = 0;
		tmp.k = 0;
		while (tmp.tmp_2 && tmp.k++ < range)
		{
			if (((t_pile*)(tmp.tmp_2->content))->val\
				< ((t_pile*)(tmp.tmp_1->content))->val)
				(tmp.i)++;
			tmp.tmp_2 = tmp.tmp_2->next;
		}
		if (tmp.i == 5 * range / 8)
			tmp.nu_med = ((t_pile*)(tmp.tmp_1->content))->val;
		tmp.tmp_1 = tmp.tmp_1->next;
	}
	return (tmp.nu_med);
}


int		lst_oct_4(t_list *lst, int range)
{
	t_lstmed	tmp;

	if (!lst)
		return (0);
	tmp.j = 0;
	tmp.nu_med = ((t_pile*)(lst->content))->val;
	tmp.tmp_1 = lst;
	while (tmp.tmp_1 && (tmp.j)++ < range)
	{
		tmp.tmp_2 = lst;
		tmp.i = 0;
		tmp.k = 0;
		while (tmp.tmp_2 && tmp.k++ < range)
		{
			if (((t_pile*)(tmp.tmp_2->content))->val\
				< ((t_pile*)(tmp.tmp_1->content))->val)
				(tmp.i)++;
			tmp.tmp_2 = tmp.tmp_2->next;
		}
		if (tmp.i == 7 * range / 8)
			tmp.nu_med = ((t_pile*)(tmp.tmp_1->content))->val;
		tmp.tmp_1 = tmp.tmp_1->next;
	}
	return (tmp.nu_med);
}
