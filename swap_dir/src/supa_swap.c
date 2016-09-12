#include "push_swap.h"

void	supa_swap(t_list **lst_a, t_list **lst_b, t_mark *mark)
{

	int	i;
	int	ret;
	int	j;
	int	len;

	len = ft_lstcount(*lst_a);
	i = 0;
	if (i < len)
	{
		j = 0;
		ret = test_sort(lst_a, lst_b, mark, len - i);
		/*while (j++ < ret)
			r_local(lst_a, mark);*/
		print_lst(*lst_a);
		ft_printf("\n");
		i += ret;
	}
}
