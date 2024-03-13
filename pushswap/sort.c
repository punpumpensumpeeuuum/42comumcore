/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:46:12 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/13 16:35:30 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort3(t_list **a)
{
	if (ft_lstsize(*a) == 2)
	{
		ra(a, 1);
		return ;
	}
	if (*(*a)->content > *(*a)->next->content)
		sa(a, 1);
	if (*(*a)->next->content > *(*a)->next->next->content)
	{
		rra(a, 1);
		if (checknext(*a))
			return ;
		sa(a, 1);
	}
}

void	preppush(t_list **stack, t_list *head, char name)
{
	while (*stack != head)
	{
		if (name == 'a')
		{
			if (head->abvmedia)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (name == 'b')
		{
			if (head->abvmedia)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	move_atob(t_list **a, t_list **b)
{
	t_list	*nodecheap;

	nodecheap = getcheapest(*a);
	if (nodecheap->abvmedia && nodecheap->target->abvmedia)
		rotateboth(a, b, nodecheap);
	else if (!(nodecheap->abvmedia) && !(nodecheap->target->abvmedia))
		rerotateboth(a, b, nodecheap);
	preppush(a, nodecheap, 'a');
	preppush(a, nodecheap->target, 'b');
	pb(b, a);
}

void	move_btoa(t_list **a, t_list **b)
{
	preppush(a, (*b)->target, 'a');
	pa(a, b);
}

void	sort_tudo(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !checknext(*a))
		pb(b, a);
	if (len_a-- > 3 && !checknext(*a))
		pb(b, a);

	while (len_a-- > 3 && !checknext(*a))
	{	
		inistack_a(*a, *b);
		move_atob(a, b);
	}
	sort3(a);
	while (*b)
	{
		inistack_a(*a, *b);
		move_btoa(a, b);
	}

	assignplace(*a);
	miniontop(a);
}
