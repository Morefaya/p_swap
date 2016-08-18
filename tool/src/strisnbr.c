/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strisnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 17:30:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 17:30:59 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tool.h"

int	strisnbr(const char *str)
{
	while (*str && ft_strchr(" \t\n", *str))
		str++;
	if (*str && ft_strchr("-+", *str))
		str++;
	while (*str && ft_strchr("0123456789", *str))
		str++;
	if (!*str)
		return (1);
	return (0);
}
