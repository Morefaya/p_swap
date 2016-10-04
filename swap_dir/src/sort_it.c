/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:25:55 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/04 20:31:54 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_elem(t_list **lst, int max)
{
	int	var;

	var = ((t_pile*)((*lst)->content))->val;
	if ((check_next(*lst) && var != max))
		swap(lst);
}

void		sort_it(t_list **lst)
{
	int	max;
	int	i;

	max = get_highest(*lst);
	i = 0;
	while (check_asc_rot(*lst) != 1)
	{
		i = 0;
		while (i < ft_lstcount(*lst))
		{
			sort_elem(lst, max);
			rotate(lst);
			i++;
		}
		i = ft_lstcount(*lst) - 1;
		while (i >= 0)
		{
			sort_elem(lst, max);
			rev_rotate(lst);
			i--;
		}
	}
	while (check_asc(*lst) != 1)
		rotate(lst);
}
