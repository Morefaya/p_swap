#include "checker.h"

int	get_option(int ac, char **av)
{
	int	i;
	int	j;
	int	opt;

	i = 1;
	opt = 0;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j] && ft_strchr(OPT, av[i][j]))
		{
			if (av[i][j] == 'a')
				opt |= OPT_A;
			else if (av[i][j] == 'b')
				opt |= OPT_B;
			j++;
		}
		i++;
	}
	return (opt);
}
