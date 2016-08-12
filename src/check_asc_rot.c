#include "push_swap.h"

int	check_asc_rot(t_list *lst)
{
	t_list	*tmp;
	int	nb_link;
	int	i;
	int	ret;

	i = 0;
	nb_link = ft_lstcount(lst);
	if (!(tmp = ft_lstcpy(lst, sizeof(t_pile))))
		return (0);
	while (!(ret = check_asc(tmp)) && i++ < nb_link)
		rotate(&tmp);
	ft_lstdel(&tmp, (void(*)(void*, size_t))del_content);
	if (!ret)
		return (0);
	else if (ret == -1)
		return (-1);
	else
		return (1);
}
