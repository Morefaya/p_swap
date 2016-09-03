#include "checker.h"

void	delete_cpy(char **av_cpy)
{
	int	i;

	i = 0;
	while (av_cpy[i])
	{
		free(av_cpy[i]);
		i++;
	}
	free(av_cpy);
}
