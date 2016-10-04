/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limit_high.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 21:51:59 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 22:26:29 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_limit_high(t_list *lst)
{
	int		highest;
	t_list	*cpy;
	int		i;
	int		limit_high;

	if (!lst)
		return (0);
	highest = get_highest(lst);
	if (!(cpy = ft_lstcpy(lst, sizeof(t_pile))))
		return (0);
	while (((t_pile*)(cpy->content))->val != highest)
		rotate(&cpy);
	limit_high = highest;
	rev_rotate(&cpy);
	i = 0;
	while (count_low(cpy, ((t_pile*)(cpy->content))->val)\
		== count_low(cpy, limit_high) - 1
		&& i++ < ft_lstcount(lst))
	{
		limit_high = ((t_pile*)(cpy->content))->val;
		rev_rotate(&cpy);
	}
	return (limit_high);
}
