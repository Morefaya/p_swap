/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:25:04 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:29:41 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tool.h"

int	max_int(int value, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && ft_strchr(" \t\n", str[i]))
		i++;
	if (str[i] && ft_strchr("+-", str[i]))
		i++;
	while (str[i] == '0')
		i++;
	while (str[i + j] && ft_strchr("0123456789", str[i + j]))
		j++;
	if ((value < 0 && !ft_strchr(str, '-'))
		|| (value > 0 && ft_strchr(str, '-'))
		|| j > 10)
		return (1);
	return (0);
}
