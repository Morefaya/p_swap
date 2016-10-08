/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:24:31 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/08 17:43:48 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*get_op_lst(void)
{
	char	*line;
	t_list	*op_lst;
	t_list	*tmp;
	t_op	content;

	op_lst = NULL;
	get_next_line(0, &line);
	content.op = line;
	if (!(op_lst = ft_lstnew(&content, sizeof(content))))
		return (NULL);
	while (get_next_line(0, &line))
	{
		content.op = line;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
			return (NULL);
		ft_lstadd_back(op_lst, tmp);
	}
	free(line);
	return (op_lst);
}
