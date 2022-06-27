/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cskipjac <cskipjac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:45:22 by cskipjac          #+#    #+#             */
/*   Updated: 2022/06/27 21:03:36 by cskipjac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_print(t_list *list)
{
	t_list	*list_b;

	list_b = list;
	while (list_b)
	{
		printf("%d ", list_b->content);
		list_b = list_b->next;
	}
	printf("\n");
}

int	ft_atoi(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		res = res * 10 + (*str++ - '0');
	return ((int)(res * sign));
}

int	check_int(char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		res = res * 10 + (*str++ - '0');
		if (res * sign > 2147483647 || (res * sign) < -2147483648)
			return (1);
	}
	return (0);
}

int	check_dublicate(int q, char **argv)
{
	while (*++argv)
	{
		if (q == ft_atoi(*argv))
			return (1);
	}
	return (0);
}

int	check_argv(char **argv)
{
	char	*e;
	int		i;

	while (*++argv)
	{
		i = -1;
		e = (char *)(*argv);
		while (e[++i])
		{
			if (e[i] < '0' || e[i] > '9')
				if (e[i] == '-' && i != 0)
					return (1);
		}
		if (check_int(*argv) || check_dublicate(ft_atoi(*argv), argv))
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*list_c;
	int		i;

	if (check_argv(av) == 1)
		write(2, "Error\n", 7);
	else if (ac == 1)
		return (0);
	else
	{
		i = 0;
		list_a = NULL;
		while (av[++i])
			ft_lstadd_back(&list_a, ft_lstnew(ft_atoi(av[i])));
		list_c = NULL;
		list_b = NULL;
		ft_ommand(&list_c, '1', '2', '3');
		main_plus(list_a, list_b, list_c);
	}
	return (0);
}

// printf("A = "); ft_print(list_a);
		// printf("B = "); ft_print(list_b);
// printf("C = "); ft_print(list_c);
		// printf("stat = "); ft_print(list_a);
