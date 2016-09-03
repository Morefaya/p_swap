#include "libft.h"

void	ft_lsttrans(t_list **lst, int range)
{
	int	i;

	if (!range)
		return ;
	i = ft_abs(range);
	while (i--)
	{
		if (range < 0)
			ft_lstrev_rotate(lst);
		ft_lstswap(lst);
		if (range > 0)
			ft_lstrotate(lst);
	}
}
