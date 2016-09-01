#include "checker.h"

int	count_arg(int ac, char ***av)
{
	int	i;

	i = 1;
	while (i < ac && *av[i][0] == '-')
		i++;
	while (i++ < ac)
		j++;
	return (j);
}
