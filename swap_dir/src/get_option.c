/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 21:07:43 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 19:44:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_option(int ac, int *opt, char **av)
{
	int	i;
	int	j;

	i = 1;
	*opt = 0;
	while (i < ac && av[i][0] == '-' && ft_strchr(OPT, av[i][1]))
	{
		j = 1;
		while (av[i][j] && ft_strchr(OPT, av[i][j]))
		{
			if (av[i][j] == 'a')
				*opt |= OPT_A;
			else if (av[i][j] == 'b')
				*opt |= OPT_B;
			j++;
		}
		i++;
	}
	return (i - 1);
}
