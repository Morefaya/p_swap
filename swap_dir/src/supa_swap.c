#include "push_swap.h"

/*void	supa_swap(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int	var;
	int	len;
	t_list	*op;

	len = ft_lstcount(*lst_a);
	op = get_lstlen(len);
	while (check_lstlen(op))
	{
		var = ((t_pile*)(op->content))->val;
		final_sort(lst_a, lst_b, mark, var);
		op = op->next;
	}
}*/

void	supa_swap(t_list **lst_a, t_list **lst_b, t_mark *mark)
{
	int	var;
	int	len;
	t_list	*op;
	int	i;

	len = ft_lstcount(*lst_a);
	op = get_quartlstlen(len);
	while (check_lstlen(op) && op)
	{
		i = 0;
		//var_next = ((t_pile*)(op->next->content))->val;
		while (i < len)
		{
			var = ((t_pile*)(op->content))->val;
			i += quart_sort(lst_a, lst_b, mark, var);
			op = op->next;
		}
		/*ft_printf("lst_a: ");
		print_lst(*lst_a);
		ft_printf("lst_b: ");
		print_lst(*lst_b);*/
		i = 0;	
		while (i < len)
		{
			var = ((t_pile*)(op->content))->val;
			//ft_printf("var = %d\n", var);
			i += quart_sort(lst_b, lst_a, mark, var);
			op = op->next;
		}
	}
}
