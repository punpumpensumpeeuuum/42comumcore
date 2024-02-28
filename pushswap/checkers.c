/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:01:17 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/28 17:10:41 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkdup(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *a;
	tmp2 = *a;
	while (tmp1->next != NULL)
	{
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
			if (tmp1->content == tmp2->content)
				return (1);
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1;
	}
	return (0);
}

int	checknumb(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (j < argc)
	{
		if (argv[j][i] == '-' && argv[j][i] == '0' && argv[j][i])
			return (0);
		if (argv[j][i] != '-' && argv[j][i] != '+')
			i++;
		while (argv[j][i])
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	minisort(t_list *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a;
	while (tmp1)
	{
		tmp2 = a;
		while (tmp2)
		{
			if (tmp1->content > tmp2->content)
				tmp1->sitio++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}
