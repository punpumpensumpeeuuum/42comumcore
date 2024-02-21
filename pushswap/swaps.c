/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:44:51 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/21 16:33:50 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_moves	*popfirst(t_moves **list)
{
	t_moves	*tmp;

	tmp = *list;
	list = (*list)->next;
	tmp->next = NULL;
	return (tmp);
}

void	sa(t_moves **list)
{
	t_moves	*tmp1;
	t_moves	*tmp2;

	tmp1 = popfirst(list);
	tmp2 = popfirst(list);
	ft_lstadd_front(list, tmp1);
	ft_lstadd_front(list, tmp2);
	ft_printf("sa\n");
}

void	sb(t_moves **list)
{
	t_moves	*tmp1;
	t_moves	*tmp2;

	tmp1 = popfirst(list);
	tmp2 = popfirst(list);
	ft_lstadd_front(list, tmp1);
	ft_lstadd_front(list, tmp2);
	ft_printf("sb\n");
}

void	ss(t_moves **a, t_moves **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}