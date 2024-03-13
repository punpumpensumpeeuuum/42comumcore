/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:25:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/13 16:31:10 by dinda-si         ###   ########.fr       */
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

void	ra(t_list **lst, int flag)
{
	t_list	*node;

	node = popfirst(lst);
	ft_lstadd_back(lst, node);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_list **lst, int flag)
{
	t_list	*node;

	node = popfirst(lst);
	ft_lstadd_back(lst, node);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
