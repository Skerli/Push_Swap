/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:34:19 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 11:34:19 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	indexing(int argc, const char **argv, t_list *buf)
{
	int	arr[1000];
	int	i;

	i = 0;
	while (*++argv)
		arr[i++] = ft_atoi(*argv);
	arr[argc - 1] = '\0';
	qs(arr, 0, argc - 2);
	while (buf)
	{
		i = -1;
		while (++i < argc - 1)
		{
			if (arr[i] == buf->content)
			{
				buf->index = i;
				break ;
			}
		}
		(buf) = (buf)->next;
	}
}

void	swap(int *i, int *j)
{
	int	q;

	q = *i;
	*i = *j;
	*j = q;
}

void	qs(int *arr, int first, int last)
{
	int	i;
	int	j;
	int	x;

	i = first;
	j = last;
	x = arr[(first + last) / 2];
	while (i <= j)
	{
		while (arr[i] < x)
			i++;
		while (arr[j] > x)
			j--;
		if (i <= j)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	if (i < last)
		qs(arr, i, last);
	if (first < j)
		qs(arr, first, j);
}

void	big_sort(t_list **lsta, t_list **lstb, int size, int q)
{
	int		i;
	t_list	*buf;
	int		schet;

	i = 0;
	while (*lsta)
	{
		buf = *lsta;
		schet = 0;
		while (buf->index > (size / q + i))
		{
			buf = buf->next;
			schet++;
		}
		if (schet <= (size - i) / 2)
			ra_rb(lsta, schet, 'a');
		else if (schet > (size - i) / 2)
			rra_rrb(lsta, size - schet - i, 'a');
		big_sort_sl(lsta, lstb, buf, i);
		i++;
	}
	lstb_to_lsta(lsta, lstb, size);
}

void	big_sort_sl(t_list **lsta, t_list **lstb, t_list *buf, int i)
{
	if (buf->index < i)
	{
		pa_pb(lsta, lstb, 1, 'b');
		ra_rb(lstb, 1, 'b');
	}
	else
	{
		pa_pb(lsta, lstb, 1, 'b');
		if ((*lstb)->next)
		{
			if ((*lstb)->index < (*lstb)->next->index)
				sa_sb(lstb, 1, 'b');
		}
	}
}
