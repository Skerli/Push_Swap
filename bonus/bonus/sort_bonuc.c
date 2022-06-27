/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonuc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:34:25 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 21:46:13 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sswap(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	if (tmp->next == NULL || tmp == NULL)
		return ;
	(*list) = (*list)->next;
	tmp->next = tmp->next->next;
	(*list)->next = tmp;
}

void	r(t_list **list)
{
	t_list	*tmp;
	t_list	*end;

	tmp = (*list);
	if (tmp->next == NULL || tmp == NULL)
		return ;
	end = *list;
	(*list) = (*list)->next;
	while (end->next)
		end = end->next;
	end->next = tmp;
	tmp->next = NULL;
}

void	rr(t_list **list)
{
	t_list	*tmp;
	t_list	*end;

	end = *list;
	if (end->next == NULL || end == NULL)
		return ;
	while (end->next->next)
		end = end->next;
	tmp = end->next;
	end->next = NULL;
	ft_lstadd_front(list, tmp);
}

void	p(t_list **list_out, t_list **list_cin)
{
	t_list	*tmp;

	if (*list_out == NULL)
		return ;
	if (*list_cin == NULL)
	{
		*list_cin = *list_out;
		*list_out = (*list_out)->next;
		(*list_cin)->next = NULL;
	}
	else
	{
		tmp = (*list_out)->next;
		(*list_out)->next = *list_cin;
		*list_cin = *list_out;
		*list_out = tmp;
	}
}

void	ssort(t_list **list_a, t_list **list_b, int com)
{
	if (com == SA)
		sswap(list_a);
	if (com == SB && *list_b != NULL)
		sswap(list_b);
	if (com == SS)
		sswap(list_a);
	if (com == SS && *list_b != NULL)
		sswap(list_b);
	if (com == PA)
		p(list_b, list_a);
	if (com == PB)
		p(list_a, list_b);
	if (com == RA || com == RR)
		r(list_a);
	if ((com == RB || com == RR) && *list_b != NULL)
		r(list_b);
	if (com == RRA || com == RRR)
		rr(list_a);
	if ((com == RRB || com == RRR) && *list_b != NULL)
		rr(list_b);
}
