/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:01:17 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/07 20:26:37 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkdup(t_list *list, int *n)
{
	if (!list)
		return (0);
	while (list)
	{
		if (*n == *list->content)
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
		if (argv[j][i] == '-' && argv[j][i] == '0' && argv[j][i])
			return (0);
		if (argv[j][i] != '-' && argv[j][i] != '+')
			i++;
		while (argv[j][i])
		{
			if (!(argv[j][i] >= 48 && argv[j][i] <= 57))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	checknext(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (*lst->content > *lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
