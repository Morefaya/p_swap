/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 20:50:25 by jcazako           #+#    #+#             */
/*   Updated: 2016/10/08 16:56:32 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "ft_printf.h"
# include "push_swap.h"

# define OPT "a"
# define OPT_A 01

int				strisnbr(const char *str);
int				puterror(int ret);
int				double_val(int *tab, int i);
int				max_int(int value, char *str);
int				check_nbr(int ac, char **av, int *tab);
t_list			*get_op_lst(void);
t_list			*lst_inttab(int *tab, int len);
void			do_op(t_list **lst_a, t_list **lst_b);
void			del_content(void *content, size_t size);
void			del_op(void *content, size_t size);
int				get_option(int ac, int *opt, char **av);
int				count_arg(int ac, char ***av);
void			operate(t_list **lst_a, t_list **lst_b, t_list **op_lst);
void			do_allop(t_list **lst_a, t_list **lst_b, t_list **op_lst);
int				count_nbr_split(char **av);
void			deal_op(int opt, t_list **lst_a, t_list **lst_b);
t_list			*deal_arg(int ac, int *opt, char **av);
char			**arg_cpy(int ac, char **av);
void			delete_cpy(char **av_cpy);
#endif
