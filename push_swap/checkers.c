/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:01:17 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/26 11:53:12 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkdup(t_list *list, int n)
{
	if (!list)
		return (0);
	while (list)
	{
		if (n == list->content)
			return (1);
		list = list->next;
	}
	return (0);
}

int	checknumb(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!(argv[j][i] >= 48 && argv[j][i] <= 57) && argv[j][i] != 32 &&
					argv[j][i] != '-' && argv[j][i] != '+')
				return (0);
			if (argv[j][i] == '-')
			{
				i++;
				if (argv[j][i] == '-' || argv[j][i] == '0')
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

bool	checknext(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (false);
		lst = lst->next;
	}
	return (true);
}

void	miniontop(t_list **a)
{
	while ((*a)->content != findmin(*a)->content)
	{
		if (findmin(*a)->abvmedia)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
