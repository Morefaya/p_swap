/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:31:50 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 17:04:44 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*deal_lstconf(t_list *lst_d, t_list *lst_a, t_list **lst_c)
{
	int		one;
	int		two;
	t_list	*tmp;
	t_pile	ct;

	one = ((t_pile*)(lst_d->content))->val;
	two = ((t_pile*)(lst_d->next->content))->val;
	ct.val = count_btw(lst_a, one, two);
	if (!(tmp = ft_lstnew(&ct, sizeof(t_pile))))
	{
		ft_lstdel(lst_c, (void(*)(void*, size_t))del_content);
		return (NULL);
	}
	ft_lstadd_back(*lst_c, tmp);
	return (*lst_c);
}

static t_list	*last_lstconf(t_list *lst_a, t_list **lst_c, int val)
{
	t_list	*tmp;
	t_pile	ct;

	ct.val = count_above(lst_a, val);
	if (!(tmp = ft_lstnew(&ct, sizeof(t_pile))))
	{
		ft_lstdel(lst_c, (void(*)(void*, size_t))del_content);
		return (NULL);
	}
	ft_lstadd_back(*lst_c, tmp);
	return (*lst_c);
}

t_list			*calc_lstconf(t_list *lst_data, t_list *lst_a)
{
	t_list	*lst_conf;
	t_pile	content;
	int		i;
	int		len_d;

	content.val = count_below(lst_a, ((t_pile*)(lst_data->content))->val);
	if (!(lst_conf = ft_lstnew(&content, sizeof(t_pile))))
		return (NULL);
	len_d = ft_lstcount(lst_data);
	i = 0;
	while (i++ < len_d - 1)
	{
		if (!(deal_lstconf(lst_data, lst_a, &lst_conf)))
			return (NULL);
		lst_data = lst_data->next;
	}
	if (!(last_lstconf(lst_a, &lst_conf, ((t_pile*)(lst_data->content))->val)))
		return (NULL);
	return (lst_conf);
}
