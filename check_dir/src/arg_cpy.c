#include "checker.h"

char **arg_cpy(int ac, char **av)
{
	char	**av_cpy;
	char	*tmp;
	int	i;

	if (!(av_cpy = (char**)malloc(sizeof(*av_cpy) * ac)))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!(tmp = ft_strdup(av[i + 1])))
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
