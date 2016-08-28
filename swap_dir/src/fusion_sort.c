#include "push_swap.h"

static int	check_a(t_list *op_a, t_list *op_b)
{
	int	i;

	i = 0;
	while (op_a && op_b)
	{
		if ((!ft_strcmp("sa", ((t_op*)(op_a->content))->op)
			&& !ft_strcmp("sb", ((t_op*)(op_b->content))->op))
			|| (!ft_strcmp("ra", ((t_op*)(op_a->content))->op)
			&& !ft_strcmp("rb", ((t_op*)(op_b->content))->op))
			|| (!ft_strcmp("rra", ((t_op*)(op_a->content))->op)
			&& !ft_strcmp("rrb", ((t_op*)(op_b->content))->op)))
			break ;
		op_b = op_b->next;
		i++;
	}
	if (!op_b)
		return (-1);
	return (i);
}


static int	check_b(t_list *op_a, t_list *op_b)
{
	int	i;

	i = 0;
	while (op_a && op_b)
	{
		if ((!ft_strcmp("sa", ((t_op*)(op_a->content))->op)
			&& !ft_strcmp("sb", ((t_op*)(op_b->content))->op))
			|| (!ft_strcmp("ra", ((t_op*)(op_a->content))->op)
			&& !ft_strcmp("rb", ((t_op*)(op_b->content))->op))
			|| (!ft_strcmp("rra", ((t_op*)(op_a->content))->op)
			&& !ft_strcmp("rrb", ((t_op*)(op_b->content))->op)))
			break ;
		op_a = op_a->next;
		i++;
	}
	if (!op_a)
		return (-1);
	return (i);
}

static void	deal_fus(t_list **op, t_list **op_a, t_list **op_b, char **tab_op)
{
	int	next_a;
	int	next_b;
	int	next;

	next = 0;
	if ((next_a = check_a(*op_a, *op_b)) < (next_b = check_b(*op_a, *op_b))
		&& next_a != -1)
	{
		//ft_putendl("A");
		next = next_a;
		while (next-- > 0)
		{
			add_op(op, ((t_op*)((*op_b)->content))->op, tab_op);
			*op_b = (*op_b)->next;
		}
	}
	else if (next_a > next_b && next_b != -1)
	{
		//ft_putendl("B");
		next = next_b;
		while (next-- > 0)
		{
			add_op(op, ((t_op*)((*op_a)->content))->op, tab_op);
			*op_a = (*op_a)->next;
		}
	}
	else if (next_a == next_b && next_a == -1)
	{
		//ft_putendl("C");
		add_op(op, ((t_op*)((*op_a)->content))->op, tab_op);
		add_op(op, ((t_op*)((*op_b)->content))->op, tab_op);
		(*op_a) = (*op_a)->next;
		(*op_b) = (*op_b)->next;
	}
	else if (next_a == next_b && next_a != -1)
	{
		//ft_putendl("C");
		if (ft_lstcount(*op_a) >= ft_lstcount(*op_b))
		{
			add_op(op, ((t_op*)((*op_a)->content))->op, tab_op);
			(*op_a) = (*op_a)->next;
		}
		else
		{
			add_op(op, ((t_op*)((*op_b)->content))->op, tab_op);
			(*op_b) = (*op_b)->next;
		}
	}	
	else if (next_a == -1)
	{
		//ft_putendl("D");
		while (!((!ft_strcmp("sa", ((t_op*)((*op_a)->content))->op)
			&& !ft_strcmp("sb", ((t_op*)((*op_b)->content))->op))
			|| (!ft_strcmp("ra", ((t_op*)((*op_a)->content))->op)
			&& !ft_strcmp("rb", ((t_op*)((*op_b)->content))->op))
			|| (!ft_strcmp("rra", ((t_op*)((*op_a)->content))->op)
			&& !ft_strcmp("rrb", ((t_op*)((*op_b)->content))->op))))
		{
			add_op(op, ((t_op*)((*op_a)->content))->op, tab_op);
			*op_a = (*op_a)->next;
		}
	}
	else if (next_b == -1)
	{
		
		//ft_putendl("E");
		while (!((!ft_strcmp("sa", ((t_op*)((*op_a)->content))->op)
			&& !ft_strcmp("sb", ((t_op*)((*op_b)->content))->op))
			|| (!ft_strcmp("ra", ((t_op*)((*op_a)->content))->op)
			&& !ft_strcmp("rb", ((t_op*)((*op_b)->content))->op))
			|| (!ft_strcmp("rra", ((t_op*)((*op_a)->content))->op)
			&& !ft_strcmp("rrb", ((t_op*)((*op_b)->content))->op))))
		{
			/*ft_putstr(((t_op*)((*op_a)->content))->op);
			ft_putchar('\t');
			ft_putstr(((t_op*)((*op_b)->content))->op);
			ft_putchar('\n');*/
			add_op(op, ((t_op*)((*op_b)->content))->op, tab_op);
			*op_b = (*op_b)->next;
		}
		
	}
	/*ft_putstr(((t_op*)((*op_a)->content))->op);
	ft_putchar('\t');
	ft_putstr(((t_op*)((*op_b)->content))->op);
	ft_putchar('\n');
	ft_putchar('\n');*/
}

static void	fusion_link(t_list **op, t_list **op_a, t_list **op_b, char **tab_op)
{
	if (!*op_a && !*op_b)
		return ;
	else if (!*op_a && *op_b)
	{	
		add_op(op, ((t_op*)((*op_b)->content))->op, tab_op);
		(*op_b) = (*op_b)->next;
		return ;
	}
	else if (*op_a && !*op_b)
	{	
		add_op(op, ((t_op*)((*op_a)->content))->op, tab_op);
		(*op_a) = (*op_a)->next;
		return ;
	}
	if (!ft_strcmp("sa", ((t_op*)((*op_a)->content))->op)
		&& !ft_strcmp("sb", ((t_op*)((*op_b)->content))->op))
	{
		add_op(op, "ss", tab_op);
		(*op_a) = (*op_a)->next;
		(*op_b) = (*op_b)->next;
	}
	else if (!ft_strcmp("ra", ((t_op*)((*op_a)->content))->op)
		&& !ft_strcmp("rb", ((t_op*)((*op_b)->content))->op))
	{
		add_op(op, "rr", tab_op);
		(*op_a) = (*op_a)->next;
		(*op_b) = (*op_b)->next;
	}
	else if (!ft_strcmp("rra", ((t_op*)((*op_a)->content))->op)
		&& !ft_strcmp("rrb", ((t_op*)((*op_b)->content))->op))
	{
		add_op(op, "rrr", tab_op);
		(*op_a) = (*op_a)->next;
		(*op_b) = (*op_b)->next;
	}
	else
		deal_fus(op, op_a, op_b, tab_op);
}

void	fusion_sort(t_list **op, t_list *op_a, t_list *op_b, char **tab_op)
{
	while (op_a || op_b)
		fusion_link(op, &op_a, &op_b, tab_op);
}
