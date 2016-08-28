#include "push_swap.h"

static int	check_dbop(t_list **op)
{
	if ((!(ft_strcmp("sa", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("sa", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("sb", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("sb", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("ra", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("rra", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("rb", ((t_op*)((*op)->content))->op))
		&& !(ft_strcmp("rrb", ((t_op*)((*op)->next->content))->op)))
		|| (!(ft_strcmp("ra", ((t_op*)((*op)->next->content))->op))
		&& !(ft_strcmp("rra", ((t_op*)((*op)->content))->op)))
		|| (!(ft_strcmp("rb", ((t_op*)((*op)->next->content))->op))
		&& !(ft_strcmp("rrb", ((t_op*)((*op)->content))->op))))
		return (1);
	return (0);
}

/*static void	pushing(t_list **op, t_list **trash, int *action, t_list **first)
{
	int	cond;

	cond = 0;
	if (*op == *first)
		cond = 1;
	push(op, trash);
	push(op, trash);
	*action = 1;
	if (cond)
		*first = *op;
}

void		check_op(t_list **op)
{
	t_list	*trash;
	int	action;
	t_list	*first;
	int	cond;
	int	i;

	if (!*op || ft_lstcount(*op) <= 1)
		return ;
	trash = NULL;
	first = *op;
	cond = 1;
	print_op(*op);
	ft_putchar('\n');
	i = 1;
	while (*op != first || cond)
	{
		ft_putstr("tour: ");
		ft_putnbr(i);
		ft_putchar('\n');
		if (i == 20)
			break;
		i++;
		cond = 0;
		action = 0;
		if (!(*op)->next)
			break ;
		if (check_dbop(op))
			pushing(op, &trash, &action, &first);
		if (!action)
			rotate(op);
		print_op(*op);
		ft_putchar('\n');
	}
	rotate(op);
	ft_lstdel(&trash, (void(*)(void*, size_t))del_content);
}*/

static int	verif_op(t_list *op)
{
	if (!op)
		return (0);
	while (op->next)
	{
		if (check_dbop(&op))
			return (1);
		op = op->next;
	}
	return (0);
}

static void	reducer(t_list *tmp, t_list **op, t_list **trash)
{
	int	i;

	i = 0;
	while (tmp != *op)
	{
		rotate (op);
		i++;
	}
	push(op, trash);
	push(op, trash);
	while (i--)
		rev_rotate(op);
}

void		check_op(t_list **op)
{
	t_list	*tmp;
	t_list	*trash;

	while (verif_op(*op))
	{
		tmp = *op;
		trash = NULL;
		while (tmp && tmp->next)
		{
			if (check_dbop(&tmp))
				reducer(tmp, op, &trash);
			tmp = tmp->next;
		}
		ft_lstdel(&trash, (void(*)(void*, size_t))del_content);
	}
}
