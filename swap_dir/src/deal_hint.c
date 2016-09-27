#include "push_swap.h"

static void	bzero_rangval(t_range *r_val)
{
	r_val->one = 0;
	r_val->two = 0;
	r_val->three = 0;
	r_val->four = 0;
}

static void	init_rangval(t_range *r_val, t_list *lst_data, int j)
{
	int	k;
	int	l;
	int	len;

	len = ft_lstcount(lst_data);
	k = len / 2 - j - 1;
	if (k < 0)
		return ;
	l = 0;
	while (l < k)
	{
		lst_data = lst_data->next;
		l++;
	}
	r_val->one = ((t_pile*)(lst_data->content))->val;
	r_val->two = ((t_pile*)(lst_data->next->content))->val;
	k = len / 2 + j;
	while (l < k)
	{
		lst_data = lst_data->next;
		l++;
	}
	r_val->three = ((t_pile*)(lst_data->content))->val;
	r_val->four = ((t_pile*)(lst_data->next->content))->val;
}

static void	sort_hint(t_hint *hint, int *i, int j)
{
	int	var;
	t_range	rg;

	bzero_rangval(&rg);
	init_rangval(&rg, hint->lst_data, j);
	var = ((t_pile*)(((t_list*)(*(hint->lst_a)))->content))->val;
//	ft_printf("var :%d\t one :%d\t two :%d\t three :%d\t four :%d\n", var, rg.one, rg.two, rg.three, rg.four);
	if (var >= rg.one && var < rg.two)
	{
		p_local(hint->lst_a, hint->lst_b, hint->mark);
		(*i)++;
	}
	else if (var >= rg.three && var < rg.four)
	{
		p_local(hint->lst_a, hint->lst_b, hint->mark);
		r_local(hint->lst_b, hint->mark);
		(*i)++;
	}
	else
	{
		hint->mark->asc = 1;
		r_local(hint->lst_a, hint->mark);	
		hint->mark->asc = 0;
	}
}

static void	sort_hint_2(t_hint *hint, int *i)
{
	int	var;
	int	first;
	int	last;

	first = get_first(hint->lst_data);
	last = get_last(hint->lst_data);
	var = ((t_pile*)(((t_list*)(*(hint->lst_a)))->content))->val;
	if (var < first)
	{
		p_local(hint->lst_a, hint->lst_b, hint->mark);
		(*i)++;
	}
	else if (var >= last)
	{
		p_local(hint->lst_a, hint->lst_b, hint->mark);
		r_local(hint->lst_b, hint->mark);
		(*i)++;
	}
}

void	deal_hint(t_hint hint)
{
	int	i;
	int	j;
	int	len;

	len = ft_lstcount(hint.lst_lim);
	j = 0;
	/*ft_printf("lst_lim: ");
	print_lst(hint.lst_lim);
	ft_printf("len :%d\n", len);*/
	while (j < len - 1)
	{
		//ft_printf("ici\n");
		i = 0;
		while (i < ((t_pile*)(hint.lst_lim->content))->val)
		{
			//ft_printf("hint\n");
			sort_hint(&hint, &i, j);
			//ft_printf("%d\n", i);
		}
		hint.lst_lim = hint.lst_lim->next;
		j++;
		//ft_printf("la\n");
	}
	i = 0;
	while (i < ((t_pile*)(hint.lst_lim->content))->val)
		sort_hint_2(&hint, &i);
}
