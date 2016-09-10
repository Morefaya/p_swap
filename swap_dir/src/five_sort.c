#include "push_swap.h"

void	five_sort(t_list **lst, int len)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (i < len)
	{
		if (check_next(*lst) && i < len - 1)
		{
			swap(lst);
			nbr++;
			while (i > 0)
			{
				rev_rotate(lst);
				i--;
				nbr++;
				if (check_next(*lst))
				{
					swap(lst);
					nbr++;
				}
				else
					break;
			}
		}
		else
		{
			rotate(lst);
			nbr++;
			i++;
		}
	}
}
