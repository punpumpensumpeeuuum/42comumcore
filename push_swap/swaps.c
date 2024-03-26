/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:44:51 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/24 00:21:35 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*popfirst(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	return (tmp);
}

void	sa(t_list **list, int flag)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*list || !(*list)->next)
		return ;
	tmp1 = popfirst(list);
	tmp2 = popfirst(list);
	ft_lstadd_front(list, tmp1);
	ft_lstadd_front(list, tmp2);
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_list **list, int flag)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*list || !(*list)->next)
		return ;
	tmp1 = popfirst(list);
	tmp2 = popfirst(list);
	ft_lstadd_front(list, tmp1);
	ft_lstadd_front(list, tmp2);
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	rerotateboth(t_list **a, t_list **b, t_list *nodecheap)
{
	while (*b != nodecheap->target && *a != nodecheap)
		rrr(a, b);
	assignplace(*a);
	assignplace(*b);
}
