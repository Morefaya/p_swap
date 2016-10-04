/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:04:39 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 20:08:15 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checking(t_list **tmp_1, t_list **tmp_2, int num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (((t_pile*)((*tmp_1)->content))->val != num)
	{
		rotate(tmp_1);
		i++;
	}
	while (((t_pile*)((*tmp_2)->content))->val != num)
	{
		rev_rotate(tmp_2);
		j++;
	}
	if (i <= j)
		return (i);
	else
		return (-1 * j);
}

int			where_is(t_list *lst, int num)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	int		ret;

	if (!lst)
		return (0);
	else if (((t_pile*)(lst->content))->val == num)
		return (0);
	if (!(tmp_1 = ft_lstcpy(lst, sizeof(t_pile))))
		return (0);
	if (!(tmp_2 = ft_lstcpy(lst, sizeof(t_pile))))
	{
		ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
		return (0);
	}
	ret = checking(&tmp_1, &tmp_2, num);
	ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
	ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
	return (ret);
}
