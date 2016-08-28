#include "push_swap.h"

char	**init_op(void)
{
	char	**tab;
	int	i;

	if (!(tab = (char**)malloc(sizeof(*tab) * 12)))
		return (NULL);
	i = 0;
	while (i < 0)
		tab[i++] = NULL;
	if (!(tab[0] = ft_strdup("sa")) || !(tab[1] = ft_strdup("sb"))
		|| !(tab[2] = ft_strdup("ss")) || !(tab[3] = ft_strdup("pa"))
		|| !(tab[4] = ft_strdup("pb")) || !(tab[5] = ft_strdup("ra"))
		|| !(tab[6] = ft_strdup("rb")) || !(tab[7] = ft_strdup("rr"))
		|| !(tab[8] = ft_strdup("rra")) || !(tab[9] = ft_strdup("rrb"))
		|| !(tab[10] = ft_strdup("rrr")))
	{
		free_init(tab);
		return (NULL);
	}
	return (tab);
}	
