/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:46:12 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/05 18:13:54 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort3(t_list **a)
{
	if ((*a)->content > ((*a)->next)->content)
		sa(a);
	if (((*a)->next)->content > (((*a)->next)->next)->content)
	{
		ra(a);
		sa(a);
	}
}

void	PRINTA(t_list *a)
{
	while (a != NULL)
	{
		ft_printf("Node: %d\n", a->content);
		a = a->next;
	}
}