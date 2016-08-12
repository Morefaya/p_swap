/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:45:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/10 20:54:03 by jcazako          ###   ########.fr       */
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
int	quick_sort(t_list **lst_a, t_list **lst_b, int opt);
int		lst_average(t_list *lst);
int		lst_average_rest(t_list *lst);
int		lst_median(t_list *lst);
int		check_asc(t_list *lst);
int		check_asc_rot(t_list *lst);
int		uni_sort(t_list *lst_a, t_list *lst_b);
void		del_content(void *content, size_t content_size);
void		snd_step(t_list **lst, int opt);
#endif
