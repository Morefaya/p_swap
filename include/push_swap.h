/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:45:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/09 16:26:20 by jcazako          ###   ########.fr       */
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
void	sort_1(t_list **lst_a, t_list **lst_b);

#endif
