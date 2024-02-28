/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:20:11 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/28 17:08:33 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"

t_list	*popfirst(t_list **list);
t_list	*poplast(t_list **list);
void	sa(t_list **list);
void	sb(t_list **list);
void	ss(t_list **a, t_list **b);
void	pa(t_list **lsta, t_list **lstb);
void	pb(t_list **lsta, t_list **lstb);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **a, t_list **b);
void	rra(t_list **list);
void	rrb(t_list **list);
void	rrr(t_list **a, t_list **b);
void	minisort(t_list *a);

#endif