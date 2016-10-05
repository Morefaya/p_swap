/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:55:29 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/05 20:30:57 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	**arg_cpy(int nb_arg, char **av)
{
	char	**av_cpy;
	char	*tmp;
	int		i;

	if (!(av_cpy = (char**)malloc(sizeof(*av_cpy) * (nb_arg + 1))))
		return (NULL);
	i = 0;
	while (i < nb_arg)
	{
		if (!(tmp = ft_strdup(av[i])))
		{
			while (i)
				free(av_cpy[i--]);
			free(av_cpy);
			return (NULL);
		}
		av_cpy[i] = tmp;
		i++;
	}
	av_cpy[i] = NULL;
	return (av_cpy);
}
