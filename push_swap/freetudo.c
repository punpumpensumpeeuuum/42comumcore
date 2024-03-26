/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freetudo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:07:17 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/26 11:51:51 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	listfree(t_list **a)
{
	t_list	*temp;

	if (!a)
		return ;
	temp = *a;
	while (*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}

void	argvfree(char **av, int ac)
{
	int	i;

	if (!av)
		return ;
	if (ac == 2)
	{
		i = 0;
		while (av[i])
		{
			free(av[i]);
			i++;
		}
		free(av);
	}
}
