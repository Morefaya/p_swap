#include "push_swap.h"

void		snd_step(t_list **lst, int opt)
{
	int	nb_link;
	int	i;

	i = 1;
	nb_link = ft_lstcount(*lst);
	while (i < nb_link / 2)
	{
		if (((((t_pile*)(*lst)->content))->val < \
			(((t_pile*)(*lst)->next->content))->val && !opt)
			|| ((((t_pile*)(*lst)->content))->val > \
			(((t_pile*)(*lst)->next->content))->val && opt))
			swap(lst);
		rotate(lst);
		i++;
	}
	rotate(lst);
	i = 1;	
	while (i < nb_link / 2)
	{
		if (((((t_pile*)(*lst)->content))->val < \
			(((t_pile*)(*lst)->next->content))->val && !opt)
			|| ((((t_pile*)(*lst)->content))->val > \
			(((t_pile*)(*lst)->next->content))->val && opt))
			swap(lst);
		rotate(lst);
		i++;
	}
	rotate(lst);
}
