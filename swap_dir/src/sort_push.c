/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:01:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/06 22:02:39 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*cpy_len(t_list *lst, int len)
{
	t_list	*cpy_sort;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	if (!(cpy_sort = ft_lstnew(lst->content, sizeof(t_pile))))
		return (NULL);
	lst = lst->next;
	while (lst && len-- > 1)
	{
		tmp = ft_lstnew(lst->content, sizeof(t_pile));
		ft_lstadd_back(cpy_sort, tmp);
		lst = lst->next;
	}
	return (cpy_sort);
}

void			sort_push(t_hint hint, t_list *lst_conf)
{
	int		len;
	t_list	*cpy_s;

	if (lst_conf->next)
		sort_push(hint, lst_conf->next);
	cpy_s = NULL;
	len = ((t_pile*)(lst_conf->content))->val;
	if (!(cpy_s = cpy_len(*(hint.lst_b), len)))
		return ;
	sort_it(&cpy_s);
	deal_sort(hint, cpy_s);
	ft_lstdel(&cpy_s, (void(*)(void*, size_t))del_content);
}
