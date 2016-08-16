#include "checker.h"

int	double_val(int *tab, int i)
{
	int	val;
	int	j;

	j = 0;
	val = tab[i];
	i--;
	while (i >= 0)
	{
		if (tab[i] == val)
			return (1);
	}
	return (0);
}
