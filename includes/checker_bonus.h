/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:47:12 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 20:39:27 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(char *str);

int		is_sorted(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	clear_mem_lst(t_list **lst);

int		ft_ommand(t_list **list_c, char ch1, char ch2, char ch3);
void	main_plus(t_list *list_a, t_list *list_b, t_list *list_c);

void	sswap(t_list **list);
void	r(t_list **list);
void	rr(t_list **list);
void	p(t_list **list_out, t_list **list_cin);
void	ssort(t_list **list_a, t_list **list_b, int com);

#endif