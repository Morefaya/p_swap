#include "push_swap.h"

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
