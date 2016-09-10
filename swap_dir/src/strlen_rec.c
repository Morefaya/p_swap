#include "push_swap.h"

int	strlen_rec(char *str)
{
	if (!str)
		return (0);
	if (*str)
		return (strlen(str++) + 1);
	return (0);
}
