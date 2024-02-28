/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:25:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/28 17:10:24 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list **lsta, t_list **lstb)
{
	t_list	*node;

	if (!*lstb)
		return ;
	node = popfirst(lstb);
	ft_lstadd_front(lsta, node);
	ft_printf("pa\n");
}

void	pb(t_list **lsta, t_list **lstb)
{
	t_list	*node;

	if (!*lsta)
		return ;
	node = popfirst(lsta);
	ft_lstadd_front(lstb, node);
	ft_printf("pb\n");
}

void	ra(t_list **lst)
{
	t_list	*node;

	node = popfirst(lst);
	ft_lstadd_back(lst, node);
	ft_printf("ra\n");
}

void	rb(t_list **lst)
{
	t_list	*node;

	node = popfirst(lst);
	ft_lstadd_back(lst, node);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
