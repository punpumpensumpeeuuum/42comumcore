/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:46:12 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/12 18:07:39 by dinda-si         ###   ########.fr       */
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

void	sort_tudo(t_list **a, t_list **b)
{
	int	lena;

	lena = ft_lstsize(*a);
	if (lena-- > 3 && !checknext(*a))
		pb(b, a);
	if (lena-- > 3 && !checknext(*a))
		pb(b, a);
}