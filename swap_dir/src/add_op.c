/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:40:07 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 20:40:09 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*cmp_op(char *op, char **tab_op)
{
	int	i;

	i = 0;
	while (tab_op[i])
	{
		if (!ft_strcmp(op, tab_op[i]))
			return (tab_op[i]);
		i++;
	}
	return (NULL);
}

void		add_op(t_list **lst, char *op, char **tab_op)
{
	t_list	*new;
	t_op	data;

	if (!lst)
		return ;
	data.op = cmp_op(op, tab_op);
	if (!(new = ft_lstnew(&data, sizeof(data))))
		return ;
	if (!*lst && data.op)
		ft_lstadd(lst, new);
	else if (data.op)
		ft_lstadd_back(*lst, new);
}
