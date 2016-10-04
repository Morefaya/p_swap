/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:01:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 20:05:26 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	returning(int i, int j, t_list **lst, t_mark *mark)
{
	int	k;

	k = 0;
	if (i <= j)
	{
		while (!check_asc(*lst))
		{
			r_local(lst, mark);
			k++;
		}
	}
	else
	{
		while (!check_asc(*lst))
		{
			rev_local(lst, mark);
			k--;
		}
	}
	return (k);
}

static int	checking(t_list **tmp_1, t_list **tmp_2, t_list **lst, t_mark *mark)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!check_asc(*tmp_1))
	{
		rotate(tmp_1);
		i++;
	}
	while (!check_asc(*tmp_2))
	{
		rev_rotate(tmp_2);
		j++;
	}
	return (returning(i, j, lst, mark));
}

int			turn_list(t_list **lst, t_mark *mark)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		ret;

	if (!lst)
		return (0);
	else if (check_asc(*lst))
		return (0);
	if (!(tmp_1 = ft_lstcpy(*lst, sizeof(t_pile))))
		return (0);
	if (!(tmp_2 = ft_lstcpy(*lst, sizeof(t_pile))))
	{
		ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
		return (0);
	}
	ret = checking(&tmp_1, &tmp_2, lst, mark);
	ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
	ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
	return (ret);
}
