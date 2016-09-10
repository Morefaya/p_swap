#include "push_swap.h"

int	test_sort(t_list **lst_a, t_list **lst_b, t_mark *mark, int len)
{
	int	i;

	i = 0;
	if (check_asc_len(*lst_a, len) == 1)
		return (len);
	else if (len < 4)
	{
		elem_sort(lst_a, mark, len);
		return (len);
	}
	final_sort(lst_a, lst_b, mark, len);
	return (test_sort(lst_a, lst_b, mark, len / 2));
}
