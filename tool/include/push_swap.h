/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 20:45:40 by jcazako           #+#    #+#             */
/*   Updated: 2016/08/17 18:02:43 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define N 0
# define S 1
# define R 2
# define REV 3

typedef struct	s_pile
{
	int			val;
}				t_pile;

t_list			*lst_tab2d(int ac, char **av);
void			print_lst(t_list *lst);
void			swap(t_list **lst);
void			push(t_list **lst_a, t_list **lst_b);
void			rotate(t_list **lst);
void			rev_rotate(t_list **lst);
void			bubble_sort(t_list **lst_a, t_list **lst_b);
int				danm_sort(t_list **lst_a, t_list **lst_b, int opt);
int				lst_average(t_list *lst);
int				lst_average_rest(t_list *lst);
int				lst_median(t_list *lst);
int				check_asc(t_list *lst);
int				check_asc_rot(t_list *lst);
int				uni_sort(t_list *lst_a, t_list *lst_b);
void			del_content(void *content, size_t content_size);
void			snd_step(t_list **lst, int opt);
int				check_prev(t_list *lst);
int				check_next(t_list *lst);
int				get_highest(t_list *lst);
int				get_lowest(t_list *lst);
int				turn_list(t_list **lst);
int				check_prevnext(t_list *lst);
int				asc_sort(t_list **lst);
int				where_is(t_list *lst, int num);
void			hard_sort(t_list **lst_a, t_list **lst_b);
void			swaping_sort(t_list **lst);
void			end_push(t_list **lst_a, t_list **lst_b);
void			main_sort(t_list **lst_a, t_list **lst_b);
void			del_content(void *content, size_t size);
void			quick_sort(t_list **lst_a, t_list **lst_b);
#endif
