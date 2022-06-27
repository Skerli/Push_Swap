/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:34:29 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 11:34:29 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*создаёт эллимент списка*/
t_list	*ft_lstnew(int content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	tmp->index = 0;
	return (tmp);
}

//добавляет новый эллимент в начало списка
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = (*lst);
	*lst = new;
}

//добавляет новый эллимент в конец списка
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!(*lst))
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

//проверяет отсортирован ли массив
int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (1);
		lst = lst->next;
	}
	return (0);
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

