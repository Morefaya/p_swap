/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:40:54 by jcazako           #+#    #+#             */
/*   Updated: 2016/09/01 20:43:07 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_op(t_list **lst_a, t_list **lst_b)
{
	char	*line;
	t_list	*tmp;
	t_op	content;

	if (!(tmp = ft_lstnew(&content, sizeof(content))))
		return ;
	while (get_next_line(0, &line))
	{
		((t_op*)(tmp->content))->op = line;
		operate(lst_a, lst_b, &tmp);
		ft_putchar('\n');
		print_lst(*lst_a);
		print_lst(*lst_b);
		ft_putchar('\n');
		free(line);
	}
	free(line);
	ft_lstdel(&tmp, (void(*)(void*, size_t))del_content);
}
