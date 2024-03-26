/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:32:09 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/23 23:29:32 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assignplace(t_list *a)
{
	int	i;
	int	m;

	i = 0;
	if (!a)
		return ;
	m = ft_lstsize(a) / 2;
	while (a)
	{
		a->place = i;
		if (i <= m)
			a->abvmedia = true;
		else
			a->abvmedia = false;
		a = a->next;
		i++;
	}
}

void	assigntarget_a(t_list *a, t_list *b)
{
	t_list	*new_b;
	t_list	*n;
	int		match;

	while (a)
	{
		match = INT_MIN;
		new_b = b;
		while (new_b)
		{
			if (new_b->content < a->content && new_b->content > match)
			{
				match = new_b->content;
				n = new_b;
			}
			new_b = new_b->next;
		}
		if (match == INT_MIN)
			a->target = findmax(b);
		else
			a->target = n;
		a = a->next;
	}
}

void	assigncost(t_list *a, t_list *b)
{
	int	lena;
	int	lenb;

	lena = ft_lstsize(a);
	lenb = ft_lstsize(b);
	while (a)
	{
		a->cost = a->place;
		if (!(a->abvmedia))
			a->cost = lena - (a->place);
		if (a->target->abvmedia)
			a->cost += a->target->place;
		else
			a->cost += lenb - (a->target->place);
		a = a->next;
	}
}

void	assigncheapest(t_list *a)
{
	int		cheapest;
	t_list	*nodecheap;

	if (!a)
		return ;
	cheapest = INT_MAX;
	while (a)
	{
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			nodecheap = a;
		}
		a = a->next;
	}
	nodecheap->cheap = true;
}

void	inistack_a(t_list *a, t_list *b)
{
	assignplace(a);
	assignplace(b);
	assigntarget_a(a, b);
	assigncost(a, b);
	assigncheapest(a);
}
