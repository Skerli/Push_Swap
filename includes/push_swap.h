/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:34:41 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 11:34:41 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	raspred_f(int size, t_list	**tmp);
void	three_sort(t_list	**tmp, int a);
void	print_t_list(t_list *tmp);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sa_sb(t_list **lst, int time, char q);
void	ra_rb(t_list **lst, int time, char q);
void	rra_rrb(t_list **lst, int time, char q);
void	swap(int *i, int *j);
void	qs(int *arr, int first, int last);
void	indexing(int argc, const char **argv, t_list *buf);
void	four_sort(t_list **lsta, t_list **lstb, int size);
void	pa_pb(t_list **lsta, t_list **lstb, int time, char q);
void	five_sort(t_list **lsta, t_list **lstb, int size);
int		ft_atoi(const char *str);
void	big_sort(t_list **lsta, t_list **lstb, int size, int q);
void	lstb_to_lsta(t_list **lsta, t_list **lstb, int size);
int		is_sorted(t_list *lst);
void	big_sort_sl(t_list **lsta, t_list **lstb, t_list *buf, int i);
void	clear_mem_lst(t_list **lst);

#endif
