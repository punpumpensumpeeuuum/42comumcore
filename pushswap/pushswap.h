/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:20:11 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/13 16:30:02 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	t_list	*head;
	int		size;
}	t_stack;

//moves
t_list	*popfirst(t_list **list);
t_list	*poplast(t_list **list);
void	sa(t_list **list, int flag);
void	sb(t_list **list, int flag);
void	ss(t_list **a, t_list **b);
void	pa(t_list **lsta, t_list **lstb);
void	pb(t_list **lsta, t_list **lstb);
void	ra(t_list **lst, int flag);
void	rb(t_list **lst, int flag);
void	rr(t_list **a, t_list **b);
void	rra(t_list **list, int flag);
void	rrb(t_list **list, int flag);
void	rrr(t_list **a, t_list **b);
void	rotateboth(t_list **a, t_list **b, t_list *nodecheap);
void	rerotateboth(t_list **a, t_list **b, t_list *nodecheap);

//main
int		checknumb(int argc, char **argv);
int		checkdup(t_list *a, int *n);
void	init(int argc, t_stack *stack);
int		getnumbers(int argc, char **argv, t_stack *a);
int		nocasodeserstring(int argc, char **argv, t_stack *a);
int		checknext(t_list *lst);
void	printa(t_list *current);

//helpers
t_list	*findmax(t_list	*a);
t_list	*findmin(t_list *a);
t_list	*getcheapest(t_list *a);
void	assigncheapest(t_list *a);
void	assigncost(t_list *a, t_list *b);
void	assigntarget_a(t_list *a, t_list *b);
void	assigntarget_b(t_list *a, t_list *b);
void	assignplace(t_list *a);
void	inistack_a(t_list *a, t_list *b);
void	inistack_b(t_list *a, t_list *b);

//sorts
void	sort3(t_list **a);
void	sort_tudo(t_list **a, t_list **b);
void	preppush(t_list **stack, t_list *head, char name);
void	move_atob(t_list **a, t_list **b);
void	move_btoa(t_list **a, t_list **b);
void	miniontop(t_list **a);

#endif