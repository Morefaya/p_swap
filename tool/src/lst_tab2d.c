/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tab2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 21:13:03 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 15:35:20 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_link(char **av)
{
	t_list	*lst;
	t_pile	content;

	if (!av || !*av)
		return (NULL);
	content.val = ft_atoi(*av);
	if (!(lst = ft_lstnew(&content, sizeof(content))))
		return (NULL);
	return (lst);
}

static void		make_link(t_list **lst, char **av)
{
	t_list	*lst_tmp;

	if ((lst_tmp = get_link(av)))
		ft_lstadd_back(*lst, lst_tmp);
}

t_list			*lst_tab2d(int ac, char **av)
{
	t_list	*lst;
	int		i;

	i = 1;
	if (!av)
		return (NULL);
	av++;
	if (!(lst = get_link(av)))
		return (NULL);
	av++;
	while (i < ac)
	{
		make_link(&lst, av);
		i++;
		av++;
	}
	return (lst);
}
