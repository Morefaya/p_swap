/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstlim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:50:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:23:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*make_lstlim(t_list *lst, int low, int high)
{
	t_list	*lst_lim;
	t_pile	data;
	t_list	*tmp;

	lst_lim = NULL;
	while (low >= 0 && high < ft_lstcount(lst))
	{
		data.val = get_lstval(lst, low) + get_lstval(lst, high);
		if (!(tmp = ft_lstnew(&data, sizeof(t_pile))))
		{
			ft_lstdel(&lst, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		if (!lst_lim)
			ft_lstadd(&lst_lim, tmp);
		else
			ft_lstadd_back(lst_lim, tmp);
		low--;
		high++;
	}
	return (lst_lim);
}

t_list			*get_lstlim(t_list *lst)
{
	t_list	*lst_lim;
	int		len;

	len = ft_lstcount(lst);
	lst_lim = make_lstlim(lst, len / 2 - 1, len / 2);
	return (lst_lim);
}
