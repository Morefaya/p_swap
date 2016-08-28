#include "push_swap.h"

void	free_init(char **tab_op)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		free(tab_op[i]);
		tab_op[i++] = NULL;
	}
	free(tab_op);
}
