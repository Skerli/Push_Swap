/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:34 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 20:49:09 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"
void	ft_print(t_list *list);

void	main_plus(t_list *list_a, t_list *list_b, t_list *list_c)
{
	while (list_c)
	{
		ssort(&list_a, &list_b, list_c->content);
		list_c = list_c->next;
	}
	if (is_sorted(list_a) == 0 && list_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	//printf("A = "); ft_print(list_a);
	//printf("B = "); ft_print(list_b);
	clear_mem_lst(&list_a);
	clear_mem_lst(&list_b);
	clear_mem_lst(&list_c);
	exit(1);
}

int	error(int content)
{
	if (content == 0)
		write(2, "Error\n", 7);
	if (content == 0)
		exit(1);
	return (1);
}

int	what_is_cm_plus(int content, char ch2, char ch3, int count)
{
	if (ch2 == 'a' && count == 4)
		content = RA;
	if (ch2 == 'b' && count == 4)
			content = RB;
	if (ch2 == 'r' && count != 5 && count == 4)
		content = RR;
	else
	{
		if (ch3 == 'a' && count == 5)
			content = RRA;
		if (ch3 == 'b' && count == 5)
			content = RRB;
		if (ch3 == 'r' && count == 5)
			content = RRR;
	}
	return (content);
}

int	what_is_cm(int count, char ch1, char ch2, char ch3)
{
	int	content;

	content = 0;
	if (ch1 == 's')
	{
		if (ch2 == 'a' && count == 4)
			content = SA;
		if (ch2 == 'b' && count == 4)
			content = SB;
		if (ch2 == 's' && count == 4)
			content = SS;
	}
	if (ch1 == 'p')
		if (ch2 == 'a' && count == 4)
			content = PA;
	if (ch1 == 'p')
		if (ch2 == 'b' && count == 4)
			content = PB;
	if (ch1 == 'r')
		content = what_is_cm_plus(content, ch2, ch3, count);
	return (content);
}

int	ft_ommand(t_list **list_c, char ch1, char ch2, char ch3)
{
	int		count;
	int		content;
	char	ch;

	count = 1;
	while (read(0, &ch, 1) > 0)
	{
		if (ch == '\n' && count == 1)
			break ;
		if (count == 1)
			ch1 = ch;
		if (count == 2)
			ch2 = ch;
		if (count == 3)
			ch3 = ch;
		count++;
		if (ch == '\n' && count >= 4)
		{
			content = what_is_cm(count, ch1, ch2, ch3);
			count = error(content);
			ft_lstadd_back(list_c, ft_lstnew(content));
			content = 0;
		}
	}
	return (0);
}
