#include "checker.h"

int	check_nbr(int ac, char **av, int *tab)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!strisnbr(av[i]))
			return (puterror(tab, 2));
		tab[i - 1] = ft_atoi(av[i]);
		if (double_val(tab, i - 1) || max_int(tab[i - 1], av[i]))
			return (puterror(tab, 3));
	}
	/*i = 0;
	while (i < ac - 1)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}*/
	return (0);
}
