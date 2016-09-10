#include "push_swap.h"

void	swap_sort(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	len;
	int	itr;
	int	j;
	int	pow;

	len = ft_lstcount(*lst_a);
	final_sort(lst_a, lst_b, len);
	itr = 1;
	pow = ft_pow(2, itr);
	while (len / pow > 1)
	{
		j = 0;
		while (j++ < pow)
		{
			i = 0;
			final_sort(lst_a, lst_b, len / pow);
			while (i++ < len / pow)
				rotate(lst_a);
			if (len % pow)
				final_sort(lst_a, lst_b, len / pow + 1);
			else
				final_sort(lst_a, lst_b, len / pow);
			i = 0;
			while (i++ < len / pow)
				rotate(lst_a);
			if (len % pow)
				rotate(lst_a);
		}
		ft_printf("end %d:\nlst_a:\n", itr);
		print_lst(*lst_a);
		ft_printf("lst_b:\n");
		print_lst(*lst_b);
		ft_printf("ft_pow: %d\n", pow);
		pow = ft_pow(2, ++itr);
	}
}
