/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_inttab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:31:09 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:31:26 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*lst_inttab(int *tab, int len)
{
	t_list	*lst_a;
	t_list	*tmp;
	t_pile	content;
	int		i;

	i = 0;
	content.val = tab[0];
	if (!(lst_a = ft_lstnew(&content, sizeof(content))))
		return (NULL);
	i = 1;
	while (i < len)
	{
		content.val = tab[i++];
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
			return (NULL);
		}
		ft_lstadd_back(lst_a, tmp);
	}
	return (lst_a);
}
