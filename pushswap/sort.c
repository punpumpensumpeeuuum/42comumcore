/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:46:12 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/06 17:05:53 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort3(t_list **a)
{
	if (*(*a)->content > *(*a)->next->content)
		sa(a);
	if (*(*a)->next->content > *(*a)->next->next->content)
	{
		ra(a);
		if (checknext(*a))
			return ;
		sa(a);
		if (checknext(*a))
			return ;
	}
}

void	printa(t_stack *stack)
{
	t_list *current = stack->head;
	while (current)
	{
		ft_printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}
