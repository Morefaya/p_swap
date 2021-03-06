/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_sort_asc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:39:43 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/22 14:42:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_limit_low(t_list *lst)
{
	int		lowest;
	t_list	*cpy;
	int		i;
	int		limit_low;

	if (!lst)
		return (0);
	lowest = get_lowest(lst);
	if (!(cpy = ft_lstcpy(lst, sizeof(t_pile))))
		return (0);
	while (((t_pile*)(cpy->content))->val != lowest)
		rotate(&cpy);
	limit_low = lowest;
	rotate(&cpy);
	i = 0;
	while (count_high(cpy, ((t_pile*)(cpy->content))->val)\
		== count_high(cpy, limit_low) - 1
		&& i++ < ft_lstcount(lst))
	{
		limit_low = ((t_pile*)(cpy->content))->val;
		rotate(&cpy);
	}
	ft_lstdel(&cpy, (void(*)(void*, size_t))del_content);
	return (limit_low);
}

static int	get_limit_high(t_list *lst)
{
	int		highest;
	t_list	*cpy;
	int		i;
	int		limit_high;

	if (!lst)
		return (0);
	highest = get_highest(lst);
	if (!(cpy = ft_lstcpy(lst, sizeof(t_pile))))
		return (0);
	while (((t_pile*)(cpy->content))->val != highest)
		rotate(&cpy);
	limit_high = highest;
	rev_rotate(&cpy);
	i = 0;
	while (count_low(cpy, ((t_pile*)(cpy->content))->val)\
		== count_low(cpy, limit_high) - 1
		&& i++ < ft_lstcount(lst))
	{
		limit_high = ((t_pile*)(cpy->content))->val;
		rev_rotate(&cpy);
	}
	ft_lstdel(&cpy, (void(*)(void*, size_t))del_content);
	return (limit_high);
}

static void	deal_swap(t_list **lst, t_mark *mark)
{
	int		highest;
	int		lowest;

	highest = get_highest(*lst);
	lowest = get_lowest(*lst);
	if (check_next(*lst) \
		&& (((t_pile*)(*lst)->content))->val != highest
		&& (((t_pile*)(*lst)->content))->val != lowest)
		s_local(lst, mark);
}

void		range_sort_asc(t_list **lst, int asc, t_mark *mark)
{
	int		lim_low;
	int		lim_high;

	mark->asc = asc;
	while (check_asc_rot(*lst) != 1)
	{
		while (check_asc_rot(*lst) != 1)
		{
			deal_swap(lst, mark);
			lim_high = get_limit_high(*lst);
			if (((t_pile*)((*lst)->content))->val >= lim_high)
				break ;
			r_local(lst, mark);
		}
		while (check_asc_rot(*lst) != 1)
		{
			deal_swap(lst, mark);
			lim_low = get_limit_low(*lst);
			if (((t_pile*)((*lst)->content))->val <= lim_low)
				break ;
			rev_local(lst, mark);
		}
	}
}
