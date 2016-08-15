#include "checker.h"

int	puterror(int *tab, int ret)
{
	free(tab);
	ft_putendl("Error");
	return (ret);
}

int	main(int ac, char **av)
{
	int	*tab;
	int	ret;
	char	*line;
	t_list	*op_lst;
	t_list	*tmp;
	t_op	content;

	if (ac == 1)
		return (0);
	if (!(tab = (int*)malloc(sizeof(*tab) * (ac - 1))))
		return (1);
	if ((ret = check_nbr(ac, av, tab)))
		return (ret);
	op_lst = NULL;
	get_next_line(0, &line);
	content.op = line;
	if (!(op_lst = ft_lstnew(&content, sizeof(content))))
		return (1);
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(0, &line);
		content.op = line;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
			return (0);
		ft_lstadd_back(op_lst, tmp);
	}
	print_op(op_lst);
	return (0);
}
