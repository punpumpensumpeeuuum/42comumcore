/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:27:59 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/13 16:26:22 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*getcheapest(t_list *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheap)
			return (a);
		a = a->next;
	}
	return (NULL);
}

t_list	*findmax(t_list	*a)
{
	t_list	*node;
	int		max;

	if (!a)
		return (NULL);
	max = INT_MIN;
	while (a)
	{
		if (*(a->content) > max)
		{
			max = *(a->content);
			node = a;
		}
		a = a->next;
	}
	return (node);
}

t_list	*findmin(t_list *a)
{
	t_list	*node;
	int		min;

	if (!a)
		return (NULL);
	min = INT_MAX;
	while (a)
	{
		if (*(a->content) < min)
		{
			min = *(a->content);
			node = a;
		}
		a = a->next;
	}
	return (node);
}

void	assigntarget_b(t_list *a, t_list *b)
{
	t_list	*new_a;
	t_list	*n;
	int		*match;

	match = NULL;
	while (b)
	{
		*match = INT_MAX;
		new_a = a;
		while (new_a)
		{
			if (new_a->content > b->content && new_a->content < match)
			{
				match = new_a->content;
				n = new_a;
			}
			new_a = new_a->next;
		}
		if (*match == INT_MAX)
			b->target = findmin(a);
		else
			b->target = n;
		b = b->next;
	}
}

void	inistack_b(t_list *a, t_list *b)
{
	assignplace(a);
	assignplace(b);
	assigntarget_b(a, b);
}
