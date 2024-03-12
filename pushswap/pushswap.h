/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:20:11 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/12 17:40:44 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	t_list	*head;
	int		sitio;
}	t_stack;

//moves
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

//main
int		checknumb(int argc, char **argv);
int		checkdup(t_list *a, int *n);
void	init(int argc, t_stack *stack);
int		getnumbers(int argc, char **argv, t_stack *a);
int		nocasodeserstring(int argc, char **argv, t_stack *a);
int		checknext(t_list *lst);
void	printa(t_list *current);

//sorts
void	sort3(t_list **a);
void	sort_tudo(t_list **a, t_list **b);

#endif