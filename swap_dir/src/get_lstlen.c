/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:22:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:22:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_dblink(t_list *lst_len)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_pile	pile_1;
	t_pile	pile_2;

	tmp_1 = NULL;
	tmp_2 = NULL;
	if (((t_pile*)(lst_len->content))->val <= 3)
	{
		cpy_link(lst_len);
		return ;
	}
	pile_1.val = ((t_pile*)(lst_len->content))->val / 2;
	pile_2.val = pile_1.val + ((t_pile*)(lst_len->content))->val % 2;
	if (!(tmp_1 = ft_lstnew(&pile_1, sizeof(t_pile)))
		|| !(tmp_2 = ft_lstnew(&pile_2, sizeof(t_pile))))
	{
		free(tmp_1);
		free(tmp_2);
		return ;
	}
	ft_lstadd_back(tmp_1, tmp_2);
	ft_lstadd_back(lst_len, tmp_1);
	return ;
}

t_list		*get_lstlen(int len)
{
	t_list	*lst_len;
	t_pile	data;
	t_list	*trash;

	trash = NULL;
	data.val = len;
	if (!(lst_len = ft_lstnew(&data, sizeof(t_pile))))
		return (NULL);
	while (check_lstlen(lst_len, 3))
	{
		make_dblink(lst_len);
		push(&lst_len, &trash);
	}
	while (trash)
		push(&trash, &lst_len);
	return (lst_len);
}
