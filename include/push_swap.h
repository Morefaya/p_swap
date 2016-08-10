/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:45:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 15:07:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_pile
{
	int			val;
}				t_pile;

t_list	*lst_tab2d(int ac, char **av);
void	print_lst(t_list *lst);
void	swap(t_list **lst);
void	push(t_list **lst_a, t_list **lst_b);
void	rotate(t_list **lst);
void	rev_rotate(t_list **lst);
void	bubble_sort(t_list **lst_a, t_list **lst_b);
void	quick_sort(t_list **lst_a, t_list **lst_b);
int		lst_average(t_list *lst);
int		lst_average_rest(t_list *lst);
int		lst_median(t_list *lst);

#endif
