/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:24:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 19:54:32 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_seek(t_seek *seek, t_list *lst)
{
	seek->tmp_1 = NULL;
	seek->tmp_2 = NULL;
	seek->len = ft_lstcount(lst);
	seek->i = 0;
	seek->j = 0;
}

static void	seeking(t_seek *seek, int var)
{
	while (seek->i < seek->len)
	{
		if (((t_pile*)(seek->tmp_1->content))->val == var)
			break ;
		rotate(&(seek->tmp_1));
		(seek->i)++;
	}
	while (seek->j < seek->len)
	{
		if (((t_pile*)(seek->tmp_2->content))->val == var)
			break ;
		rev_rotate(&(seek->tmp_2));
		(seek->j)++;
	}
}

int			seek_way(t_list *lst, int var)
{
	t_seek	seek;

	init_seek(&seek, lst);
	if (!(seek.tmp_1 = ft_lstcpy(lst, sizeof(t_pile)))
		|| !(seek.tmp_2 = ft_lstcpy(lst, sizeof(t_pile))))
	{
		ft_lstdel(&(seek.tmp_1), (void(*)(void*, size_t))del_content);
		ft_lstdel(&(seek.tmp_2), (void(*)(void*, size_t))del_content);
		return (0);
	}
	seeking(&seek, var);
	ft_lstdel(&seek.tmp_1, (void(*)(void*, size_t))del_content);
	ft_lstdel(&seek.tmp_2, (void(*)(void*, size_t))del_content);
	if (seek.i <= seek.j)
		return (seek.i);
	else
		return (-1 * seek.j);
}
