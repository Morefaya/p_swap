#include "push_swap.h"

int	get_limit_low(t_list *lst)
{
	int	lowest;
	t_list	*cpy;
	int	i;
	int	limit_low;

	if (!lst)
		return (0);
	lowest = get_lowest(lst);
	if (!(cpy = ft_lstcpy(lst, sizeof(t_pile))))
		return (0);
	while (((t_pile*)(cpy->content))->val != lowest)
		rotate(&cpy);
	limit_low = lowest;
	rotate(&cpy);
	i = 0;
	while (count_high(cpy, ((t_pile*)(cpy->content))->val)\
		== count_high(cpy, limit_low) - 1
		&& i++ < ft_lstcount(lst))
	{
		limit_low = ((t_pile*)(cpy->content))->val;
		rotate(&cpy);
	}
	return (limit_low);
}
