/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:34:59 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 11:34:59 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_sb(t_list **lst, int time, char q)
{
	t_list	*buf;

	while (time--)
	{
		if (q == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
		buf = (*lst);
		(*lst) = (*lst)->next;
		buf->next = buf->next->next;
		(*lst)->next = buf;
	}
}

void	ra_rb(t_list **lst, int time, char q)
{
	t_list	*buf;
	t_list	*buf1;

	while (time--)
	{
		if (q == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
		buf = (*lst);
		(*lst) = (*lst)->next;
		buf1 = (*lst);
		buf->next = NULL;
		while (buf1)
		{
			if ((buf1)->next == NULL)
			{
				(buf1)->next = buf;
				break ;
			}
			(buf1) = (buf1)->next;
		}
	}
}

void	rra_rrb(t_list **lst, int time, char q)
{
	t_list	*buf;
	t_list	*buf1;

	while (time--)
	{
		if (q == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
		buf = (*lst);
		while (*lst)
		{
			if ((*lst)->next->next == NULL)
			{
				buf1 = (*lst)->next;
				(*lst)->next->next = buf;
				(*lst)->next = NULL;
			}
			(*lst) = (*lst)->next;
		}
		*lst = buf1;
	}
}

void	pa_pb(t_list **lsta, t_list **lstb, int time, char q)
{
	t_list	*buf;

	while (time--)
	{	
		if (q == 'a')
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
		if (*lstb == NULL)
		{
			*lstb = *lsta;
			*lsta = (*lsta)->next;
			(*lstb)->next = NULL;
		}
		else
		{
			buf = (*lsta)->next;
			(*lsta)->next = (*lstb);
			*lstb = *lsta;
			(*lsta) = buf;
		}
	}
}

void	clear_mem_lst(t_list **lst)
{
	t_list	*buf;

	while (*lst)
	{
		buf = (*lst)->next;
		free(*lst);
		*lst = buf;
	}
}
