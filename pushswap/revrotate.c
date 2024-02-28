/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:38:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/22 15:35:58 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*poplast(t_list **list)
{
	t_list	*tmp;

	tmp = ft_lstlast(*list);
	while ((*list)->next != tmp)
		list = &(*list)->next;
	(*list)->next = NULL;
	return (tmp);
}

void	rra(t_list **list)
{
	t_list	*node;

	node = poplast(list);
	ft_lstadd_front(list, node);
	ft_printf("rra\n");
}

void	rrb(t_list **list)
{
	t_list	*node;

	node = poplast(list);
	ft_lstadd_front(list, node);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	ft_printf("rra\n");
}
