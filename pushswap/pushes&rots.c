/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes&rots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:25:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/16 18:26:44 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_moves **lsta, t_moves **lstb)
{
	t_moves	*node;

	if (!lstb)
		return ;
	node = first(lstb);
	ft_lstadd_front(lsta, node);
	ft_printf("pa\n");
}

void	pb(t_moves **lsta, t_moves **lstb)
{
	t_moves	*node;

	if (!lsta)
		return ;
	node = first(lsta);
	ft_lstadd_front(lstb, node);
	ft_printf("pb\n");
}

void	ra(t_moves **lst)
{
	t_moves *node;
	
	node = first(lst);
	ft_lstadd_back(lst, node);
	ft_printf("ra\n");
}

void	rb(t_moves **lst)
{
	t_moves *node;
	
	node = first(lst);
	ft_lstadd_back(lst, node);
	ft_printf("rb\n");
}

void	rr(t_moves **a, t_moves **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}