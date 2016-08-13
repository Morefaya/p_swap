/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 19:01:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/13 19:21:06 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checking(t_list **tmp_1, t_list **tmp_2, t_list **lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check_asc(*tmp_1))
	{
		rotate(tmp_1);
		i++;
	}
	while (check_asc(*tmp_2))
	{
		rev_rotate(tmp_2);
		j++;
	}
	if (i <= j)
		while (!check_asc(*lst))
			rotate(lst);
	else
		while (!check_asc(*lst))
			rev_rotate(lst);
}

void		turn_list(t_list **lst)
{
	t_list	*tmp_1;
	t_list	*tmp_2;

	if (!lst)
		return ;
	else if (check_asc(*lst))
		return ;
	if (!(tmp_1 = ft_lstcpy(*lst, sizeof(t_pile))))
		return ;
	if (!(tmp_2 = ft_lstcpy(*lst, sizeof(t_pile))))
	{
		ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
		return ;
	}
	checking(&tmp_1, &tmp_2, lst);
	ft_lstdel(&tmp_1, (void(*)(void*, size_t))del_content);
	ft_lstdel(&tmp_2, (void(*)(void*, size_t))del_content);
}
