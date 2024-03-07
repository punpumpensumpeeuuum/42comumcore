/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:46:12 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/07 19:16:27 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort3(t_list **a)
{
	if (*(*a)->content > *(*a)->next->content)
		sa(a);
	if (*(*a)->next->content > *(*a)->next->next->content)
	{
		rra(a);
		if (checknext(*a))
			return ;
		sa(a);
	}
}

void	printa(t_list *current)
{
	while (current)
	{
		ft_printf("%d\n", *(int *)current->content);
		current = current->next;
	}
}
