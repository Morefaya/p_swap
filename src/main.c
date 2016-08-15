/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:43:49 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/13 20:06:58 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_content(void *content, size_t size)
{
	ft_bzero(content, size);
	free(content);
}

int		main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	//int	ret;
	//int	i;

	lst_a = NULL;
	lst_b = NULL;
	if (!(lst_a = lst_tab2d(ac, av)))
		return (1);

	//print_lst(lst_a);
	//print_lst(lst_b);

	/*if (check_asc_rot(lst_a) == 1)
	{
		turn_list(&lst_a);
		print_lst(lst_a);
		return (0);
	}*/
	/*if (ac)
	{
		ret = quick_sort(&lst_a, &lst_b , 1);
		i = 0;
		ret = quick_sort(&lst_a, &lst_b, 1);
		while (i++ < ret)
		{
			push(&lst_b, &lst_a);
			ft_putendl("P");
		}
		i = 0;
		ret = quick_sort(&lst_b, &lst_a, 0);
		while (i++ < ret)
		{
			push(&lst_a, &lst_b);
			ft_putendl("P");
		}
	}*/
	/*i = 0;
	while (i++ < 4)
	{
		print_lst(lst_a);
		print_lst(lst_b);
		ft_putchar('\n');
		rev_rotate(&lst_a);
		push(&lst_a, &lst_b);
	}
	while (lst_b)
		push(&lst_b, &lst_a);
	print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');*/

	/*while (check_asc_rot(lst_a) != 1)
	{
		print_lst(lst_a);
		do_op(&lst_a, (ret = asc_sort(&lst_a)));
		if (ret == S)
			ft_putendl("sa");
		else if (ret == R)
			ft_putendl("ra");
		else if (ret == REV)
			ft_putendl("rra");
	}
	ret = turn_list(&lst_a);
	if (ret > 0)
	{
		while (ret--)
			ft_putendl("ra");
	}
	else if (ret < 0)
	{
		while (ret++)
			ft_putendl("rra");
	}*/
//	print_lst(lst_a);
//	snd_step(&lst_a, 1);
//	snd_step(&lst_b, 0);

	/*if (ac > 20)
		while (lst_b)
			push(&lst_b, &lst_a);*/
	/*print_lst(lst_a);
	print_lst(lst_b);
	ft_putchar('\n');*/
	while (42)
	{
		if (ft_lstcount(lst_a) == 2)
		{
			if (check_next(lst_a))
			{
				swap(&lst_a);
				ft_putendl("sa");
				/*print_lst(lst_a);
				print_lst(lst_b);
				ft_putchar('\n');*/

			}
			break ;
		}
		hard_sort(&lst_a, &lst_b);
		/*print_lst(lst_a);
		print_lst(lst_b);
		ft_putchar('\n');*/
	}
	while (lst_b)
	{
		push(&lst_b, &lst_a);
		ft_putendl("pa");
		/*print_lst(lst_a);
		print_lst(lst_b);
		ft_putchar('\n');*/
	}

	ft_lstdel(&lst_a, (void(*)(void*, size_t))del_content);
	ft_lstdel(&lst_b, (void(*)(void*, size_t))del_content);
	return (0);
}
