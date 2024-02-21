/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:38:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/21 13:04:36 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_moves	*poplast(t_moves **list)
{
	t_moves	*tmp;

	tmp = ft_lstlast(list);
	while ((*list)->next != tmp)
		list = (*list)->next;
	(*list)->next = NULL;
	return (tmp);
}

void	rra(t_moves **list)
{
	t_moves *node;

	node = poplast(list);
	ft_lstadd_front(list, node);
	ft_printf("rra\n");
}

void	rrb(t_moves **list)
{
	t_moves *node;

	node = poplast(list);
	ft_lstadd_front(list, node);
	ft_printf("rrb\n");
}

void	rrr(t_moves **a, t_moves **b)
{
	rra(a);
	rrb(b);
	ft_printf("rra\n");
}
