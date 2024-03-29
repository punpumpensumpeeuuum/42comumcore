/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:38:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/24 00:21:54 by elemesmo         ###   ########.fr       */
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

void	rra(t_list **list, int flag)
{
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	node = *list;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(list, node);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **list, int flag)
{
	t_list	*node;

	if (!*list || !(*list)->next)
		return ;
	node = *list;
	while (node->next->next)
		node = node->next;
	node = poplast(&node);
	ft_lstadd_front(list, node);
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

void	rotateboth(t_list **a, t_list **b, t_list *nodecheap)
{
	while (*b != nodecheap->target && *a != nodecheap)
		rr(a, b);
	assignplace(*a);
	assignplace(*b);
}
