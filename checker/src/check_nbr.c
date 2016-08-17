/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:29:55 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:30:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_nbr(int ac, char **av, int *tab)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!strisnbr(av[i]))
			return (puterror(tab, 2));
		tab[i - 1] = ft_atoi(av[i]);
		if (double_val(tab, i - 1) || max_int(tab[i - 1], av[i]))
			return (puterror(tab, 3));
	}
	return (0);
}
