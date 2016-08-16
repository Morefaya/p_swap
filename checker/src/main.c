#include "checker.h"

int	puterror(int *tab, int ret)
{
	free(tab);
	ft_putendl_fd("Error", 2);
	return (ret);
}

void	del_op(void *content, size_t size)
{
	free(((t_op*)(content))->op);
	ft_bzero(content, size);
	free(content);
}

int	main(int ac, char **av)
{
	int	*tab;
	int	ret;
	t_list	*op_lst;
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac == 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(*tab) * (ac - 1))))
		return (1);
	if ((ret = check_nbr(ac, av, tab)))
		return (ret);
	if (!(op_lst = get_op_lst()))
		return (1);
	if (!(lst_a = lst_inttab(tab, ac - 1)))
		return (1);
	lst_b = NULL;
	do_op(&lst_a, &lst_b, op_lst);
	if (check_asc(lst_a) == 1)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_lstdel(&op_lst, (void(*)(void*, size_t))del_op);
	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	return (0);
}
