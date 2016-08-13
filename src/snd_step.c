#include "push_swap.h"

void		snd_step(t_list **lst, int opt)
{
	int	nb_link;
	int	i;
	int	value;
	int	value_next;
	int	low;

	i = 0;
	nb_link = ft_lstcount(*lst);
	low = (((t_pile*)(*lst)->content))->val;
	rotate(lst);
	while ((((t_pile*)(*lst)->content))->val != low)
	{
		//print_lst(*lst);
		//ft_putchar('\n');
		if ((((t_pile*)(*lst)->content))->val < low)
			low
		value = (((t_pile*)(*lst)->content))->val;
		value_next = (((t_pile*)(*lst)->next->content))->val;
		if (!check_prev(*lst))
			rev_totate(lst)
		else if (check_prev(*lst) && check_next(*lst))
			rotate(lst);

	}
	//print_lst(*lst);
	//ft_putchar('\n');
}
